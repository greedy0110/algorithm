//
// Created by 신승민 on 2021/09/21.
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

// 1. build scc graph by Tarjan
// 2. find scc node, the ind of which is zero.
// 3. sort original node and print.

int n, m, cnt = 0;
vvi g, scc_g, scc;
vi ind, scc_id, dfs_id;
vb found_scc;
stack<int> dfs_s;

void init_g() {
    g = vvi(n);
    dfs_id = vi(n, -1);
    scc_id = vi(n, -1);
    found_scc = vb(n, false);
    dfs_s = stack<int>();
    cnt = 0;
}

void init_scc() {
    int sn = scc.size();
    scc_g = vvi(sn);
    ind = vi(sn, 0);

    for (int u = 0; u < n; u++) {
        int uid = scc_id[u];
        for (int v : g[u]) {
            int vid = scc_id[v];
            if (uid == vid) continue;
            scc_g[uid].push_back(vid);
        }
        sort(all(scc_g[uid]));
        scc_g[uid].erase(unique(all(scc_g[uid])), scc_g[uid].end());
    }

    for (int u = 0; u < sn; u++) {
        for (int v : scc_g[u]) {
            ind[v]++;
        }
    }
}

void solve() {
    int sn = scc.size();
    vb reach(sn, false);
    bool only_one = false;
    queue<int> q;
    vi ans;
    for (int uid = 0; uid < sn; uid++) {
        if (ind[uid] == 0) {
            q.push(uid);
            if (only_one == false) {
                reach[uid] = true;
                only_one = true;
            }
            ans.push_back(uid);
        }
    }

    for (int i = 0; i < sn; i++) {
        int u = q.front();
        q.pop();

        for (int v : scc_g[u]) {
            if (reach[u]) reach[v] = true;
            ind[v]--;
            if (ind[v] == 0) q.push(v);
        }
    }

    for (int i = 0; i < sn; i++) {
        if (!reach[i]) {
            cout << "Confused" << endl;
            return;
        }
    }

    vi g_ans;
    for (int a : ans) {
        for (int i = 0; i < n; i++) {
            if (scc_id[i] == a) g_ans.push_back(i);
        }
    }

    sort(all(g_ans));
    for (int a : g_ans) cout << a << endl;
    cout << endl;
}

int build_scc(int u) {
    dfs_id[u] = ++cnt;
    dfs_s.push(u);

    int result = dfs_id[u];
    for (int v : g[u]) {
        if (dfs_id[v] == -1) result = min(result, build_scc(v));
        else if (!found_scc[v]) result = min(result, dfs_id[v]);
    }

    if (result == dfs_id[u]) {
        vi curScc;
        while (true) {
            int t = dfs_s.top();
            dfs_s.pop();
            found_scc[t] = true;
            scc_id[t] = scc.size();
            if (t == u) break;
        }
        scc.push_back(curScc);
    }

    return result;
}

void build() {
    for (int u = 0; u < n; u++) {
        if (dfs_id[u] == -1) build_scc(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        init_g();

        RP(_, m) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }

        build();
        init_scc();
        solve();
    }

    return 0;
}
