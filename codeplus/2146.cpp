//
// Created by 신승민 on 2021/07/30.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vb> vvb;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vvi A(N, vi(N));
    vvi I(N, vi(N, -1));
    RP(i, N) RP(j, N) cin >> A[i][j];

    vvi D(N, vi(N, -1));
    queue<pair<int, int>> extend_q;

    int land = 0;
    RP(i, N) {
        RP(j, N) {
            if (A[i][j] == 0) continue;
            if (I[i][j] != -1) continue;
            land++;

            queue<pair<int, int>> q;
            I[i][j] = land;
            q.push({i, j});

            while (!q.empty()) {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                D[cx][cy] = 0;
                extend_q.push({cx, cy});

                for (int d = 0; d < 4; d++) {
                    int nx = cx + dx[d], ny = cy + dy[d];

                    if (nx < 0 || N <= nx || ny < 0 || N <= ny) continue;
                    if (A[nx][ny] == 0) continue;
                    if (I[nx][ny] != -1) continue;

                    I[nx][ny] = I[cx][cy];
                    q.push({nx, ny});
                }
            }
        }
    }

    int ans = 1000;
    while (!extend_q.empty()) {
        int cx = extend_q.front().first;
        int cy = extend_q.front().second;
        int dist = D[cx][cy];
        extend_q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];

            if (nx < 0 || N <= nx || ny < 0 || N <= ny) continue;
            if (D[nx][ny] != -1) {
                if (I[cx][cy] != I[nx][ny]) {
                    ans = min(ans, D[nx][ny] + dist);
                }
                continue;
            }

            D[nx][ny] = dist + 1;
            I[nx][ny] = I[cx][cy];
            extend_q.push({nx, ny});
        }
    }

    cout << ans << endl;

    return 0;
}
