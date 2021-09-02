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

vvi A;
int N, M;
vector<vb> visited;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (visited[nx][ny]) continue;
                if (A[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> M >> N >> K;
        A = vvi(N, vi(M, 0));
        visited = vector<vb>(N, vb(M, false));
        RP(_, K) {
            int a, b;
            cin >> a >> b;
            A[b][a] = 1;
        }

        int cnt = 0;
        RP(x, N) {
            RP(y, M) {
                if (!visited[x][y] && A[x][y] == 1) {
                    cnt++;
                    dfs(x, y);
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
