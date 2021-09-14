//
// Created by 신승민 on 2021/09/13.
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

void print(int v, vi &prev) {
    if (v == -1) return;
    print(prev[v], prev);
    cout << v + 1 << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<ll> dist(n, 1e18);
    vector<int> prev(n, -1);
    RP(_, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].push_back({v - 1, -w});
    }

    dist[0] = 0;
    vi cycles;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto &p: g[j]) {
                int v = p.first, d = p.second;
                if (dist[j] != 1e18 && dist[v] > dist[j] + d) {
                    prev[v] = j;
                    dist[v] = dist[j] + d;
                    if (i == n - 1) cycles.push_back(v);
                }
            }
        }
    }

    vb visited(n, false);
    queue<int> q;
    for (int c : cycles) {
        visited[c] = true;
        q.push(c);
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

    // n-1이 도달 불가능 하거나, 음의 사이클로부터 n-1이 도달 가능하면...
    if (dist[n - 1] == 1e18 || visited[n - 1]) cout << -1 << endl;
    else {
        print(n - 1, prev);
    }

    return 0;
}
