//
// Created by 신승민 on 2021/08/05.
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
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, N;
    char A[100][100];
    pii s{-1, -1}, e{-1, -1};
    cin >> M >> N;
    RP(x, N) {
        string temp;
        cin >> temp;
        RP(y, M) {
            A[x][y] = temp[y];

            if (A[x][y] == 'C') {
                if (s.first == -1) {
                    s = {x, y};
                } else {
                    e = {x, y};
                }
                A[x][y] = '.';
            }
        }
    }

    vvi D(N, vi(M, -1));
    queue<pii> dq;
    D[s.first][s.second] = -1;
    dq.push(s);

    while (!dq.empty()) {
        int cx, cy;
        tie(cx, cy) = dq.front();
        int dist = D[cx][cy];
        dq.pop();

        for (int k = 0; k < 4; k++) {
            for (int i = 1; i < max(M, N); i++) {
                int nx = cx + dx[k] * i, ny = cy + dy[k] * i;
                if (nx < 0 || N <= nx || ny < 0 || M <= ny) break;
                if (A[nx][ny] == '*') break;
                if (D[nx][ny] != -1) continue;
                D[nx][ny] = dist + 1;
                dq.push({nx, ny});
            }
        }
    }

    cout << D[e.first][e.second] << endl;

    return 0;
}
