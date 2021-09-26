//
// Created by 신승민 on 2021/09/26.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'
#define custom_pq(X) priority_queue<X, vector<X>, X>

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<int, int> pii;

int cnt, n;
vi dfs_n, scc_id, scc_topology;
vb finished;
vvi g, scc, sg;
stack<int> dfs_s;

void init_g() {
    cnt = 0;
    dfs_n = vi(n, -1);
    scc_id = vi(n, -1);
    finished = vb(n, false);
}

int build_scc(int u) {
    int result = dfs_n[u] = ++cnt;
    dfs_s.push(u);

    for (int v : g[u]) {
        if (dfs_n[v] == -1) result = min(result, build_scc(v));
        else if (!finished[v]) result = min(result, dfs_n[v]);
    }
    if (result == dfs_n[u]) {
        vi cur_scc;
        while (true) {
            int t = dfs_s.top();
            dfs_s.pop();
            cur_scc.push_back(t);
            scc_id[t] = scc.size();
            finished[t] = true;
            if (t == u) break;
        }
        scc.push_back(cur_scc);
    }
    return result;
}

void build() {
    for (int i = 0; i < n; i++) if (dfs_n[i] == -1) build_scc(i);
}

void init_sg() {
    int sn = scc.size();
    sg = vvi(sn);

    vi ind(sn, 0);
    for (int u = 0; u < n; u++) {
        int uid = scc_id[u];
        assert(uid != -1);
        auto &ug = sg[uid];
        for (int v : g[u]) {
            int vid = scc_id[v];
            if (uid == vid) continue;
            ug.push_back(vid);
        }
    }

    for (int u = 0; u < sn; u++) {
        for (int v: sg[u]) {
            ind[v]++;
        }
    }

    scc_topology.clear();
    queue<int> q;
    for (int i = 0; i < sn; i++) {
        if (ind[i] == 0) q.push(i);
    }

    for (int i = 0; i < sn; i++) {
        assert(!q.empty());
        int u = q.front();
        q.pop();
        scc_topology.push_back(u);

        for (int v : sg[u]) {
            ind[v]--;
            if (ind[v] == 0) q.push(v);
        }
    }
    assert(q.empty());
    assert(scc_topology.size() == sn);
}

vi manipulate_by_scc_topology() {
    vi ret;
    for (int u : scc_topology) {
        ret.insert(ret.end(), all(scc[u]));
    }
    assert(ret.size() == n);
    return ret;
}

void solve(int target) {
    vector<ll> rank(n, 1);
    auto order = manipulate_by_scc_topology();
    vb visited(n, false);
    for (int i = 0; i < n; i++) {
        int u = order[i];
        int uid = scc_id[u];
        for (int v : g[u]) {
            if (visited[v]) continue;
            int vid = scc_id[v];
            if (uid == vid) continue;
            rank[v] += rank[u];
        }
        visited[u] = true;
    }
    cout << rank[target] << endl;
}

map<string, int> indices;

int index_from(const string &key) {
    if (indices.find(key) == indices.end()) {
        indices[key] = g.size();
        g.emplace_back();
    }
    return indices[key];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num;
    cin >> num;

    RP(_, num) {
        string uword;
        int ch_num;
        cin >> uword >> ch_num;
        int u = index_from(uword);

        RP(x, ch_num) {
            // vword -> uword 가리킨다.
            string vword;
            cin >> vword;
            int v = index_from(vword);
            g[v].push_back(u);
        }
    }
    n = g.size();
    init_g();
    build();
    init_sg();

    string target;
    cin >> target;
    solve(indices[target]);

    return 0;
}
