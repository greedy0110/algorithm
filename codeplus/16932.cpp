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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vvi A(N, vi(M));
    vvi G(N, vi(M, -1));
    RP(x, N) RP(y, M) cin >> A[x][y];

    vi sizes;
    int group = 0;
    int ans = 0;

    RP(x, N) {
        RP(y, M) {
            if (G[x][y] != -1) continue;
            if (A[x][y] == 0) continue;
            int cnt = 0;
            // 새로운 그룹 발견. BFS 하면서 칠하기
            queue<pair<int, int>> q;
            G[x][y] = group;
            q.push({x, y});

            while (!q.empty()) {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                cnt++;

                for (int k = 0; k < 4; k++) {
                    int nx = cx + dx[k], ny = cy + dy[k];

                    if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                        if (A[nx][ny] == 1 && G[nx][ny] == -1) {
                            q.push({nx, ny});
                            G[nx][ny] = group;
                        }
                    }
                }
            }

            ans = max(ans, cnt);
            sizes.push_back(cnt);
            group++;
        }
    }

    RP(x, N) {
        RP(y, M) {
            if (G[x][y] == -1) {
                assert(A[x][y] == 0);
                int cnt = 1; // x,y 를 1로 만듬.
                set<int> gs;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                        if (G[nx][ny] != -1) {
                            gs.insert(G[nx][ny]);
                        }
                    }
                }
                for (int g : gs) {
                    // 그룹이 있으면 합친다.
                    cnt += sizes[g];
                }
                ans = max(ans, cnt);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
