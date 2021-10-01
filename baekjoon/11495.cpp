//
// Created by 신승민 on 2021/10/01.
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

int rowSize, colSize;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int to_index(int row, int col) {
    return row * colSize + col;
}

bool blue_node(int row, int col) {
    return (row + col) % 2 == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> rowSize >> colSize;
        int NODE_SIZE = rowSize * colSize + 2;
        int s = NODE_SIZE - 2, e = NODE_SIZE - 1, max_flow = 0, all_sum = 0;
        vvi g(NODE_SIZE);
        vvi cap(NODE_SIZE, vi(NODE_SIZE, 0));
        vvi flow(NODE_SIZE, vi(NODE_SIZE, 0));
        RP(row, rowSize) {
            RP(col, colSize) {
                int w, v = to_index(row, col);
                assert(0 <= v && v < rowSize * colSize);
                cin >> w;
                all_sum += w;
                // blue node는 시작점과 연결하자.
                if (blue_node(row, col)) {
                    cap[s][v] = w;
                    g[s].push_back(v);
                    g[v].push_back(s);
                }
                    // red node는 종료점과 연결하자.
                else {
                    cap[v][e] = w;
                    g[v].push_back(e);
                    g[e].push_back(v);
                }
            }
        }
        RP(row, rowSize) {
            RP(col, colSize) {
                if (blue_node(row, col)) {
                    // blue node 부터 인접한 빨간 노드에 연결하자.
                    int u = to_index(row, col);
                    RP(i, 4) {
                        int nRow = row + dx[i], nCol = col + dy[i];
                        if (0 <= nRow && nRow < rowSize && 0 <= nCol && nCol < colSize) {
                            int v = to_index(nRow, nCol);
                            cap[u][v] = 1e9;
                            g[u].push_back(v);
                            g[v].push_back(u);
                        }
                    }
                }
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
                for (int v : g[u]) {
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
            max_flow += cur_flow;
        }
        cout << all_sum - max_flow << endl;
    }

    return 0;
}
