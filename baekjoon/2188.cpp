//
// Created by 신승민 on 2021/09/28.
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

    int n, m;
    cin >> n >> m;
    int s = n + m, e = n + m + 1, total = 0;
    const int NODE_SIZE = n + m + 2;
    vvi capacity(NODE_SIZE, vi(NODE_SIZE, 0));
    vvi flow(NODE_SIZE, vi(NODE_SIZE, 0));

    RP(u, n) {
        int si;
        cin >> si;
        capacity[s][u] = 1; // 시작 -> 소
        RP(_, si) {
            int z;
            cin >> z; //  1~m
            int v = n + z - 1; // n~n+m-1
            assert(0 <= u && u < n && n <= v && v < n + m);
            capacity[u][v] = 1;
            capacity[v][e] = 1; // 축사 -> 종료
        }
    }

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
                if (capacity[u][v] - flow[u][v] <= 0)continue;
                prev[v] = u;
                if (v == e) break;
                q.push(v);
            }
        }

        if (prev[e] == -1) break;
        int cur_flow = 1e9;
        for (int v = e; v != s; v = prev[v]) {
            int u = prev[v];
            cur_flow = min(cur_flow, capacity[u][v] - flow[u][v]);
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
