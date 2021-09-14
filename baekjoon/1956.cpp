//
// Created by 신승민 on 2021/09/15.
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

    int v, e;
    const int INF = 1e9;
    cin >> v >> e;
    vvi dist(v + 1, vi(v + 1, INF));
    RP(_, e) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= v; i++) ans = min(ans, dist[i][i]);
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}
