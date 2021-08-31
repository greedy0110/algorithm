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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int W, H;
vvi A;

bool in_board(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

vi bfs(int s, vector<pair<int, int>> dust) {
    int sx = dust[s].first;
    int sy = dust[s].second;

    vvi D(H, vi(W, -1));
    queue<pair<int, int>> q;
    D[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        int cd = D[cx][cy];
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k], ny = cy + dy[k];
            if (in_board(nx, ny)) {
                if (A[nx][ny] == 'x') continue;
                if (D[nx][ny] != -1) continue;

                D[nx][ny] = cd + 1;
                q.push({nx, ny});
            }
        }
    }

    vi ret(dust.size());
    for (int i = 0; i < dust.size(); i++) {
        int x = dust[i].first;
        int y = dust[i].second;

        ret[i] = D[x][y];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) break;
        A = vvi(H, vi(W));
        vector<pair<int, int>> dust;
        int sp = -1;
        RP(x, H) {
            string temp;
            cin >> temp;
            RP(y, W) {
                A[x][y] = temp[y];

                if (A[x][y] == '*' || A[x][y] == 'o') {
                    dust.push_back({x, y});
                    if (A[x][y] == 'o') {
                        sp = (int) dust.size() - 1;
                    }
                }
            }
        }
        int DUST = dust.size();
        if (DUST == 1) {
            cout << -1 << endl;
            return 0;
        }

        vvi dist(DUST, vi(DUST));
        bool ok = true;
        for (int i = 0; i < DUST; i++) {
            vi ret = bfs(i, dust);
            for (int j = 0; j < DUST; j++) {
                if (ret[j] == -1) {
                    ok = false;
                    break;
                }
                dist[i][j] = ret[j];
            }
        }

        if (!ok) {
            cout << -1 << endl;
            continue;
        }

        vi per(DUST);
        int ans = -1;
        for (int i = 0; i < DUST; i++) per[i] = i;
        do {
            if (per[0] != sp) continue; // 시작점으로부터 시작해야한다.
            int ret = 0;
            for (int i = 0; i < DUST - 1; i++) {
                ret += dist[per[i]][per[i + 1]];
            }
            if (ans == -1) ans = ret;
            else ans = min(ans, ret);
        } while (next_permutation(all(per)));

        cout << ans << endl;
    }

    return 0;
}
