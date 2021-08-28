//
// Created by 신승민 on 2021/08/28.
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
int h, w;
vector<vector<char>> bd;

void dfs(int sx, int sy, vvi &D) {
    deque<pair<int, int>> q;
    q.push_back({sx, sy});
    D[sx][sy] = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop_front();
        int dist = D[cx][cy];

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k], ny = cy + dy[k];

            if (0 <= nx && nx < h + 2 && 0 <= ny && ny < w + 2) {
                if (D[nx][ny] != -1) continue;

                if (bd[nx][ny] == '#') {
                    D[nx][ny] = dist + 1;
                    q.push_back({nx, ny});
                } else if (bd[nx][ny] == '.') {
                    D[nx][ny] = dist;
                    q.push_front({nx, ny}); // 문을 열지 않으니 소모값이 없다.
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> h >> w;
        // ********** 외벽을 설치해서, 상근이가 밖을 자유롭게 이동가능하도록 하자.
        bd = vector<vector<char>>(h + 2, vector<char>(w + 2, '.'));

        int x1 = -1, y1, x2, y2;
        RP(x, h) {
            string temp;
            cin >> temp;
            RP(y, w) {
                char cur = temp[y];
                bd[x + 1][y + 1] = cur;

                if (cur == '$') {
                    if (x1 == -1) {
                        x1 = x + 1;
                        y1 = y + 1;
                    } else {
                        x2 = x + 1;
                        y2 = y + 1;
                    }
                    bd[x + 1][y + 1] = '.';
                }
            }
        }

        // D[x][y] -> x, y 까지 도달하기 위해 열어야 하는 문의 최솟값.
        // H[x][y] -> x, y 도달할 때 전 x, y 좌표를 저장함.
        // *********** 상근, 죄수1, 죄수2 가 각자 문을 열다가 만났을 때.
        vvi D1(h + 2, vi(w + 2, -1));
        vvi D2(h + 2, vi(w + 2, -1));
        vvi D3(h + 2, vi(w + 2, -1));

        dfs(0, 0, D1);
        dfs(x1, y1, D2);
        dfs(x2, y2, D3);

        int ans = 100 * 100 + 1;
        for (int x = 1; x < h + 1; x++) {
            for (int y = 1; y < w + 1; y++) {
                // 만났다면...
                if (D1[x][y] != -1 && D2[x][y] != -1 && D3[x][y] != -1) {
                    int total = D1[x][y] + D2[x][y] + D3[x][y];
                    if (bd[x][y] == '#') total -= 2;
                    ans = min(ans, total);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
