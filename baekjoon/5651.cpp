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

vvi cap;
vvi flow;
int n, m;

// s -> e 로 단순 증가 간선이 있냐? 이동할 수 있냐? 1로라도.
bool find_s_to_e(int s, int e) {
    vi prev(n, -1);
    prev[s] = s;
    queue<int> q;
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

    if (prev[e] == -1) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cap = vvi(n, vi(n, 0));
        flow = vvi(n, vi(n, 0));
        vvi edge_counter(n, vi(n, 0));


        RP(_, m) {
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            cap[a][b] += c;
            edge_counter[a][b]++;
        }

        int s = 0, e = n - 1, total = 0;
        // 최대 찾기 (O(VE^2))
        while (true) {
            vi prev(n, -1);
            prev[s] = s;
            queue<int> q;
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

        int ans = 0;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (cap[u][v] == 0) continue;
                if (cap[u][v] == flow[u][v]) {
                    cap[u][v]--; // 1 줄여보고 경로를 찾는다.
                    flow[u][v]--;
                    flow[v][u]++;
                    if (find_s_to_e(u, v)) ans += edge_counter[u][v];
                    flow[u][v]++;
                    flow[v][u]--;
                    cap[u][v]++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
