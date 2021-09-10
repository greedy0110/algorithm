//
// Created by 신승민 on 2021/09/10.
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

typedef vector<vector<pair<int, ll>>> Graph;

int n, m, f, s, t;
Graph G;

ll dijkstra() {
    // 가장 가까운 거리부터 출발하는 거.
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> q;
    vector<vector<ll>> dist(n, vector<ll>(2, 10e12));
    vector<vb> visited(n, vb(2, false));
    dist[s][1] = 0;
    q.push({0, s, 1});
    while (!q.empty()) {
        ll cd;
        int u, ticket;
        tie(cd, u, ticket) = q.top();
        q.pop();

        if (visited[u][ticket]) continue;
        visited[u][ticket] = true;

        for (auto &vc : G[u]) {
            int v = vc.first;
            ll c = vc.second;

            if (c == 0 && ticket == 1) {
                // 티켓 있을 때만 이용 가능.
                if (dist[v][0] > cd + c) {
                    dist[v][0] = cd + c;
                    q.push({dist[v][0], v, 0});
                }
            } else if (c != 0) {
                if (dist[v][ticket] > cd + c) {
                    dist[v][ticket] = cd + c;
                    q.push({dist[v][ticket], v, ticket});
                }
            }

        }
    }

    return min(dist[t][0], dist[t][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> f >> s >> t;
    G = Graph(n);
    RP(_, m) {
        int i, j;
        ll c;
        cin >> i >> j >> c;
        G[i].push_back({j, c});
        G[j].push_back({i, c});
    }

    RP(_, f) {
        int i, j;
        cin >> i >> j;
        G[i].push_back({j, 0});
    }
    ll ans = dijkstra();

    cout << ans << endl;

    return 0;
}
