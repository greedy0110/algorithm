//
// Created by 신승민 on 2021/07/29.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, N;
    cin >> M >> N;
    int A[1001][1001];
    RP(x, N) RP(y, M) cin >> A[x][y];

    vector<vector<int>> D(N, vector<int>(M, -1));
    queue<pair<int, int>> q;
    RP(x, N) {
        RP(y, M) {
            if (A[x][y] == 1) {
                D[x][y] = 0;
                q.push(make_pair(x, y));
            } else if (A[x][y] == -1) {
                D[x][y] = 0;
            }
        }
    }

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir], ny = cy + dy[dir];

            if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
            if (D[nx][ny] != -1) continue;
            if (A[nx][ny] == -1) continue;

            D[nx][ny] = D[cx][cy] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    int ans = 0;
    RP(x, N) {
        RP(y, M) {
            if (D[x][y] == -1) {
                cout << -1 << endl;
                return 0;
            }
            ans = max(ans, D[x][y]);
        }
    }
    cout << ans << endl;

    return 0;
}
