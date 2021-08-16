//
// Created by 신승민 on 2021/08/16.
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

vvi A;
int N, M, L, R;

bool in_board(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

int go(int sx, int sy) {
    vvi RD(N, vi(M, -1));
    vvi LD(N, vi(M, -1));

    queue<pair<int, int>> q;
    RD[sx][sy] = 0;
    LD[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        int cr = RD[cx][cy];
        int cl = LD[cx][cy];

        int nx, ny;
        // 아래 노빠구.
        for (nx = cx + 1; nx < N; nx++) {
            if (A[nx][cy] == 1) break;
            if (RD[nx][cy] != -1) continue;
            RD[nx][cy] = cr;
            LD[nx][cy] = cl;
            q.push({nx, cy});
        }

        // 위 노빠꾸.
        for (nx = cx - 1; nx >= 0; nx--) {
            if (A[nx][cy] == 1) break;
            if (RD[nx][cy] != -1) continue;
            RD[nx][cy] = cr;
            LD[nx][cy] = cl;
            q.push({nx, cy});
        }

        // 왼쪽으로 한 칸.
        ny = cy - 1;
        if (in_board(cx, ny) && A[cx][ny] != 1 && RD[cx][ny] == -1) {
            RD[cx][ny] = cr;
            LD[cx][ny] = cl + 1;
            q.push({cx, ny});
        }

        // 오른쪽으로 한 칸.
        ny = cy + 1;
        if (in_board(cx, ny) && A[cx][ny] != 1 && RD[cx][ny] == -1) {
            RD[cx][ny] = cr + 1;
            LD[cx][ny] = cl;
            q.push({cx, ny});
        }
    }

    int ans = 0;
    RP(x, N) {
        RP(y, M) {
            if (RD[x][y] != -1 && RD[x][y] <= R && LD[x][y] <= L) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> L >> R;
    A = vvi(N, vi(M));
    int sx, sy;
    RP(x, N) {
        string temp;
        cin >> temp;
        RP (y, M) {
            A[x][y] = temp[y] - '0';

            if (A[x][y] == 2) {
                sx = x;
                sy = y;
                A[x][y] = 0;
            }
        }
    }

    cout << go(sx, sy) << endl;

    return 0;
}
