//
// Created by 신승민 on 2021/08/31.
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

int H, W, K;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int hx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool in_board(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> K >> W >> H;
    vvi A(H, vi(W));
    RP(x, H) RP(y, W) cin >> A[x][y];
    vector<vvi> D(H, vvi(W, vi(K + 1, -1)));

    queue<tuple<int, int, int>> q;
    D[0][0][0] = 0;
    q.push({0, 0, 0});

    while (!q.empty()) {
        int cx, cy, cj;
        tie(cx, cy, cj) = q.front();
        int cd = D[cx][cy][cj];
        q.pop();

        if (cj < K) { // 말의 뜀을 할 수 있다.
            for (int k = 0; k < 8; k++) {
                int nx = cx + hx[k], ny = cy + hy[k], nj = cj + 1;
                if (in_board(nx, ny)) {
                    if (D[nx][ny][nj] == -1 && A[nx][ny] == 0) {
                        D[nx][ny][nj] = cd + 1;
                        q.push({nx, ny, nj});
                    }
                }
            }
        }

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k], ny = cy + dy[k], nj = cj;
            if (in_board(nx, ny)) {
                if (D[nx][ny][nj] == -1 && A[nx][ny] == 0) {
                    D[nx][ny][nj] = cd + 1;
                    q.push({nx, ny, nj});
                }
            }
        }
    }

    int ans = -1;
    for (int a : D[H - 1][W - 1]) {
        if (a == -1) continue;
        if (ans == -1) ans = a;
        else ans = min(ans, a);
    }
    cout << ans << endl;

    return 0;
}
