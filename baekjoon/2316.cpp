//
// Created by 신승민 on 2021/09/29.
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

int NODE_SIZE;
vvi cap;

int edmonds(int s, int e) {
    vvi flow(NODE_SIZE, vi(NODE_SIZE, 0));
    int total = 0;
    while (true) {
        vi prev(NODE_SIZE, -1);
        queue<int> q;
        prev[s] = s;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < NODE_SIZE; v++) {
                if (prev[v] != -1) continue;
                if (cap[u][v] - flow[u][v] <= 0) continue;
                prev[v] = u;
                q.push(v);
            }
        }
        if (prev[e] == -1) break;
        int cur_flow = 1e9;
        for (int v = e; v != s; v = prev[v]) {
            int u = prev[v];
            cur_flow = min(cur_flow, cap[u][v] - flow[u][v]);
        }
        for (int v = e; v != s; v = prev[v]) {
            int u = prev[v];
            flow[u][v] += cur_flow;
            flow[v][u] -= cur_flow;
        }
        total += cur_flow;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, p;
    cin >> n >> p;
    NODE_SIZE = 2 * n;
    int s1 = 0, e1 = n + 1;
    cap = vvi(NODE_SIZE, vi(NODE_SIZE, 0));
    RP(_, p) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int u_ = u + n, v_ = v + n;
        cap[u][u_] = cap[v][v_] = cap[u_][v] = cap[v_][u] = 1;
    }
    cap[0][n] = cap[1][n + 1] = 1e9;

    cout << edmonds(s1, e1) << endl;

    return 0;
}
