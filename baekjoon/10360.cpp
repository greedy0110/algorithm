//
// Created by 신승민 on 2021/09/14.
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> g(n);
        vector<ll> dist(n, 1e18);
        RP(_, m) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
        }

        dist[0] = 0;
        vi cycles;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (auto &p : g[j]) {
                    int next = p.first, d = p.second;
                    if (dist[j] != 1e18 && dist[next] > dist[j] + d) {
                        dist[next] = dist[j] + d;
                        if (i == n - 1) cycles.push_back(next);
                    }
                }
            }
        }

        // 음의 사이클에서 0으로 도달 가능하면? possible
        vb visited(n, false);
        queue<int> q;
        for (int c : cycles) {
            q.push(c);
            visited[c] = true;
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto &p : g[cur]) {
                int v = p.first;
                if (visited[v]) continue;
                visited[v] = true;
                q.push(v);
            }
        }

        cout << "Case #" << t << ": ";
        if (visited[0]) cout << "possible" << endl;
        else cout << "not possible" << endl;
    }

    return 0;
}
