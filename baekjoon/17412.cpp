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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, p;
    cin >> n >> p;
    int s = 0, e = 1, total = 0;
    vvi cap(n, vi(n, 0));
    vvi flow(n, vi(n, 0));
    RP(_, p) {
        int a, b;
        cin >> a >> b;
        cap[a - 1][b - 1] = 1;
    }

    while (true) {
        vi prev(n, -1);
        queue<int> q;
        prev[s] = s;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; v++) {
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
    cout << total << endl;

    return 0;
}
