//
// Created by 신승민 on 2021/08/02.
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
typedef vector<vb> vvb;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vvi A(N, vi(M)), G(N, vi(M, -1)), ans(N, vi(M, 0));
    RP(i, N) {
        string temp;
        cin >> temp;
        RP(j, M) {
            A[i][j] = temp[j] - '0';
        }
    }

    int g = -1;
    vi gs;
    RP(i, N) {
        RP(j, M) {
            if (G[i][j] != -1) continue;
            if (A[i][j] == 1) continue;
            g++;
            int gsize = 0;

            queue<pair<int, int>> q;
            G[i][j] = g;
            q.push({i, j});

            while (!q.empty()) {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                gsize++;

                for (int d = 0; d < 4; d++) {
                    int nx = cx + dx[d], ny = cy + dy[d];

                    if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
                    if (G[nx][ny] != -1) continue;
                    if (A[nx][ny] == 1) continue;

                    G[nx][ny] = g;
                    q.push({nx, ny});
                }
            }
            gs.push_back(gsize);
            assert(gs[g] == gsize);
        }
    }

    RP(x, N) {
        RP(y, M) {
            if (A[x][y] == 0) continue;

            int sz = 1;
            set<int> nbs;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];

                if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
                if (A[nx][ny] == 1) continue;
                assert(G[nx][ny] != -1);
                nbs.insert(G[nx][ny]);
            }

            for (int gn : nbs) {
                sz += gs[gn];
            }

            ans[x][y] = sz;
        }
    }

    RP(x, N) {
        RP(y, M) {
            cout << ans[x][y] % 10;
        }
        cout << endl;
    }


    return 0;
}
