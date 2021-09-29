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

// 1. scc (scc, scc_id)

vvi g, scc;
vi scc_id, dfs_n;
vb finished;
stack<int> dfs_s;
int n, cnt;
vector<pair<int, int>> ans;

vector<vb> interfit;

void init_g() {
    cnt = 0;
    g = vvi(n, vi(n));
    scc_id = vi(n, -1);
    dfs_n = vi(n, -1);
    finished = vb(n, false);
    dfs_s = stack<int>();
    scc.clear();
}

int build_scc(int u) {
    dfs_n[u] = ++cnt;
    dfs_s.push(u);

    int result = dfs_n[u];
    for (int v = 0; v < n; v++) {
        if (g[u][v] == 1) {
            if (dfs_n[v] == -1) result = min(result, build_scc(v));
            else if (!finished[v]) result = min(result, dfs_n[v]);
        }
    }

    if (result == dfs_n[u]) {
        vi cur_scc;
        while (true) {
            int t = dfs_s.top();
            dfs_s.pop();
            finished[t] = true;
            scc_id[t] = scc.size();
            cur_scc.push_back(t);
            if (t == u) break;
        }
        scc.push_back(cur_scc);
    }
    return result;
}

void build() {
    for (int i = 0; i < n; i++) if (dfs_n[i] == -1) build_scc(i);
}

void init_scc() {
    int sn = scc.size();
    interfit = vector<vb>(sn, vb(sn, false));
}

void bfs(int scc_node) {
    auto &nodes = scc[scc_node];

    vb visited(n, false);
    queue<int> q;
    visited[nodes.front()] = true;
    q.push(nodes.front());

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (g[u][v] == 1) {
                int vid = scc_id[v];
                if (vid != scc_node) continue;
                if (visited[v]) continue;
                assert(scc_id[u] == scc_id[v]);
                visited[v] = true;
                ans.push_back({u, v});
                q.push(v);
            }
        }
    }
}

void inter() {
    for (int u = 0; u < n; u++) {
        int uid = scc_id[u];
        for (int v = 0; v < n; v++) {
            if (g[u][v] == 0) continue;
            int vid = scc_id[v];
            if (uid == vid) continue;
            if (!interfit[uid][vid]) {
                assert(scc_id[u] != scc_id[v]);
                ans.push_back({u, v});
                interfit[uid][vid] = true;
            }
        }
    }
}

void solve() {
    for (int i = 0; i < scc.size(); i++) {
        bfs(i);
    }

    inter();

    cout << ans.size() << endl;
    for (auto &a: ans) {
        cout << a.first + 1 << " " << a.second + 1 << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        init_g();
        RP(i, n) {
            string temp;
            cin >> temp;
            RP(j, n) {
                g[i][j] = temp[j] - '0';
            }
        }
        build();
        init_scc();
        solve();
    }

    return 0;
}
