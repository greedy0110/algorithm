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
vvi g, scc;
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
    scc.clear();
}

void init_scc() {
    int sn = scc.size();
    ind = vi(sn, 0);

    for (int u = 0; u < n; u++) {
        int uid = scc_id[u];
        for (int v : g[u]) {
            int vid = scc_id[v];
            if (uid == vid) continue;
            ind[vid]++;
        }
    } // O(n + m)
}

void solve() { // O(n log n)
    int sn = scc.size();
    int ans_scc_node = -1;
    for (int uid = 0; uid < sn; uid++) { // O(n)
        if (ind[uid] == 0) {
            if (ans_scc_node == -1) {
                ans_scc_node = uid;
            } else {
                cout << "Confused" << endl << endl;
                return;
            }
        }
    }

    sort(all(scc[ans_scc_node])); // O(nlogn)
    for (int a : scc[ans_scc_node]) cout << a << endl; // O(n)
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
            curScc.push_back(t);
            scc_id[t] = scc.size();
            if (t == u) break;
        }
        scc.push_back(curScc);
    }

    return result;
}

void build() {
    for (int u = 0; u < n; u++) {
        if (dfs_id[u] == -1) {
            build_scc(u);
        }
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

        RP(i, m) {
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
