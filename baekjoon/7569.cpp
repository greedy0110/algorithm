//
// Created by 신승민 on 2021/09/02.
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

int A[101][101][101];
int D[101][101][101];
int N, M, H;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dz[] = {1, -1};

bool in_board(int x, int y, int z) {
    return 0 <= x && x < N && 0 <= y && y < M && 0 <= z && z < H;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N >> H;

    queue<tuple<int, int, int>> q;
    RP(z, H) {
        RP(x, N) {
            RP(y, M) {
                cin >> A[x][y][z];
                D[x][y][z] = -1;

                if (A[x][y][z] == 1) {
                    A[x][y][z] = 0; // 토마토 그냥 0으로 표준화.
                    D[x][y][z] = 0;
                    q.push({x, y, z});
                }
            }
        }
    }

    int ans = -1;
    while (!q.empty()) {
        int cx, cy, cz;
        tie(cx, cy, cz) = q.front();
        int cd = D[cx][cy][cz];
        q.pop();
        ans = max(ans, cd);

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i], nz = cz;
            if (in_board(nx, ny, nz)) {
                if (D[nx][ny][nz] == -1 && A[nx][ny][nz] == 0) {
                    D[nx][ny][nz] = cd + 1;
                    q.push({nx, ny, nz});
                }
            }
        }

        for (int i = 0; i < 2; i++) {
            int nx = cx, ny = cy, nz = cz + dz[i];
            if (in_board(nx, ny, nz)) {
                if (D[nx][ny][nz] == -1 && A[nx][ny][nz] == 0) {
                    D[nx][ny][nz] = cd + 1;
                    q.push({nx, ny, nz});
                }
            }
        }
    }

    RP(z, H) {
        RP(x, N) {
            RP(y, M) {
                // 토마톤데 안익음;
                if (D[x][y][z] == -1 && A[x][y][z] == 0) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
