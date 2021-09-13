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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[500];
    vector<ll> dist(n, 1e18);
    RP(_, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
    }

    dist[0] = 0;
    bool minusCycle = false;
    for (int i = 0; i < n; i++) {
        // n-1 번 반복하면, 최단 경로를 구할 수 있다. n 번 반복때도 갱신된다면, 음의 사이클이 있는 것이다.
        for (int j = 0; j < n; j++) {
            // j 정점에서 갈 수 있는 모든 정점을 갱신하자.
            for (auto &p : g[j]) {
                int v = p.first;
                int d = p.second;
                if (dist[j] != 1e18 && dist[v] > dist[j] + d) {
                    dist[v] = dist[j] + d;
                    if (i == n - 1) minusCycle = true;
                }
            }
        }
    }

    if (minusCycle) cout << -1 << endl;
    else {
        for (int i = 1; i < dist.size(); i++) {
            cout << (dist[i] == 1e18 ? -1 : dist[i]) << endl;
        }
    }

    return 0;
}
