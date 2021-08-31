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

vvi safe;
vvi A;
int N, M;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool in_board(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

void bfs(int sx, int sy) {
    // sx, sy 기준으로, 아기상어일 때, safe 갱신.
    if (A[sx][sy] == 0) return;

    vvi D(N, vi(M, -1));
    queue<pair<int, int>> q;
    D[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        int cd = D[cx][cy];
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (in_board(nx, ny)) {
                if (D[nx][ny] == -1) {
                    D[nx][ny] = cd + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    RP(x, N) {
        RP(y, M) {
            if (safe[x][y] == -1) safe[x][y] = D[x][y];
            else safe[x][y] = min(safe[x][y], D[x][y]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    A = vvi(N, vi(M));
    safe = vvi(N, vi(M, -1));
    RP(x, N) RP(y, M) cin >> A[x][y];

    RP(x, N) RP(y, M) bfs(x, y);

    int ans = 0;
    RP(x, N) RP(y, M) ans = max(ans, safe[x][y]);

    cout << ans << endl;

    return 0;
}
