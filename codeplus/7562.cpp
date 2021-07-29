//
// Created by 신승민 on 2021/07/29.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int L;
        cin >> L;
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        if (sx == ex && sy == ey) {
            cout << 0 << endl;
            continue;
        }

        vector<vector<int>> dist(L, vector<int>(L, -1));

        queue<pair<int, int>> q;
        dist[sx][sy] = 0;
        q.push(make_pair(sx, sy));
        bool ans = false;

        while (!ans && !q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for (int d = 0; d < 8; d++) {
                int nx = cx + dx[d], ny = cy + dy[d];

                if (nx < 0 || L <= nx || ny < 0 || L <= ny) continue;
                if (dist[nx][ny] != -1) continue;

                dist[nx][ny] = dist[cx][cy] + 1;

                if (nx == ex && ny == ey) {
                    cout << dist[nx][ny] << endl;
                    ans = true;
                    break;
                }

                q.push(make_pair(nx, ny));
            }
        }
    }

    return 0;
}
