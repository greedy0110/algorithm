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

// 1. scc tarjan (- scc_node_count[node], scc_id[g_node], scc_count)
// 2. make scc_g
// 3. dfs from scc_id[S] to scc_id[T], memorize cities.
// 4. summarize with scc_node_count!

int n, m, s, t, cnt, scc_count;
vvi g;
vi scc_id, bfs_n;
vb finished;
stack<int> bfs_s;

vi scc_node_count;
vvi scc_g;

void init_g() {
    g = vvi(n);
    scc_id = vi(n, -1);
    finished = vb(n, false);
    bfs_n = vi(n, -1);
    cnt = 0;
    scc_count = 0;
}

int build_scc(int u) {
    bfs_n[u] = ++cnt;
    bfs_s.push(u);

    int result = bfs_n[u];
    for (int v : g[u]) {
        if (bfs_n[v] == -1) result = min(result, build_scc(v));
        else if (!finished[v]) result = min(result, bfs_n[v]);
    }

    if (result == bfs_n[u]) {
        int cur_cnt = 0;
        while (true) {
            int temp = bfs_s.top();
            bfs_s.pop();
            cur_cnt++;
            finished[temp] = true;
            scc_id[temp] = scc_count;
            if (temp == u) break;
        }
        scc_count++;
        scc_node_count.push_back(cur_cnt);
    }

    return result;
}

void build() {
    for (int i = 0; i < n; i++) if (bfs_n[i] == -1) build_scc(i);
}

void init_scc() {
    scc_g = vvi(scc_count);

    for (int u = 0; u < n; u++) {
        int uid = scc_id[u];
        auto &sg = scc_g[uid];
        for (int v : g[u]) {
            int vid = scc_id[v];
            if (uid == vid) continue;
            sg.push_back(vid);
        }
    }
}

void solve() {
    s = scc_id[s];
    t = scc_id[t];
    // dist, u
    priority_queue<pair<int, int>> q;
    vi dist(scc_count, 0);
    vb visited(scc_count, false);
    dist[s] = scc_node_count[s];
    q.push({dist[s], s});

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int v : scc_g[u]) {
            if (dist[v] < dist[u] + scc_node_count[v]) {
                dist[v] = dist[u] + scc_node_count[v];
                q.push({dist[v], v});
            }
        }
    }

    cout << dist[t] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> s >> t;
    s--;
    t--;
    init_g();
    RP(_, m) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    build();
    init_scc();
    solve();

    return 0;
}
