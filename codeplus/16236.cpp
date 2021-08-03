//
// Created by 신승민 on 2021/08/03.
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

int N;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

tuple<int, int, int> bfs(vvi &A, int s, int e, int ssize) {
    vvi D(N, vi(N, -1));
    queue<pair<int, int>> q;
    D[s][e] = 0;
    q.push({s, e});

    vector<tuple<int, int, int>> eatable;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (A[cx][cy] != 0 && A[cx][cy] < ssize) { // 작은 것만 먹을 수 있음.
            eatable.emplace_back(D[cx][cy], cx, cy);
        }

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];

            if (nx < 0 || N <= nx || ny < 0 || N <= ny) continue;
            if (D[nx][ny] != -1) continue;
            if (A[nx][ny] > ssize) continue; // 크면 못지나감.

            D[nx][ny] = D[cx][cy] + 1;
            q.push({nx, ny});
        }
    }

    if (eatable.empty()) return {-1, -1, -1};

    sort(all(eatable));
    return eatable[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vvi A(N, vi(N));
    pair<int, int> se;
    RP(i, N) {
        RP(j, N) {
            cin >> A[i][j];

            if (A[i][j] == 9) {
                se = {i, j};
                A[i][j] = 0;
            }
        }
    }

    int ssize = 2, eaten = 0, ans = 0;
    while (true) {
        int fs, fe, took;
        tie(took, fs, fe) = bfs(A, se.first, se.second, ssize);
        if (fs == -1) break;

        ans += took;

        eaten++;
        if (eaten == ssize) {
            ssize++;
            eaten = 0;
        }

        A[fs][fe] = 0;
        se = {fs, fe};
    }

    cout << ans << endl;

    return 0;
}
