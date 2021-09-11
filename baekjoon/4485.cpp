//
// Created by 신승민 on 2021/09/11.
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

typedef tuple<int, int, int> node;

int n;
vvi g;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dijkstra() {
    priority_queue<node, vector<node>, greater<>> q;
    vvi dist(n, vi(n, 1e9));
    vector<vb> visited(n, vb(n, false));
    dist[0][0] = g[0][0];
    q.push({dist[0][0], 0, 0});
    while (!q.empty()) {
        int cd, cx, cy;
        tie(cd, cx, cy) = q.top();
        q.pop();

        if (visited[cx][cy]) continue;
        visited[cx][cy] = true;

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k], ny = cy + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                int &nd = dist[nx][ny];
                int cc = g[nx][ny];
                if (nd > cd + cc) {
                    nd = cd + cc;
                    q.push({nd, nx, ny});
                }
            }
        }
    }

    return dist[n - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int p = 1;; p++) {
        cin >> n;
        if (n == 0) break;
        g = vvi(n, vi(n));
        RP(i, n) RP(j, n) cin >> g[i][j];

        cout << "Problem " << p << ": ";
        cout << dijkstra() << endl;
    }

    return 0;
}
