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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vvi A(N, vi(M));
    int D[1000][1000][11][2] = {};
//    int D[10][10][10][10] = {};

    RP(x, N) {
        string temp;
        cin >> temp;
        RP(y, M) {
            A[x][y] = temp[y] - '0';
        }
    }

    queue<tuple<int, int, int, int>> q;
    D[0][0][K][1] = 1;
    q.push({0, 0, K, 1});

    while (!q.empty()) {
        int cx, cy, ck, cdaytime;
        tie(cx, cy, ck, cdaytime) = q.front();
        int dist = D[cx][cy][ck][cdaytime];
        q.pop();

        if (cx == N - 1 && cy == M - 1 && dist != -1) {
            cout << dist << endl;
            return 0;
        }

        if (D[cx][cy][ck][1 - cdaytime] == 0) { // 가만히 있을 수 있으면 그래보자.
            D[cx][cy][ck][1 - cdaytime] = dist + 1;
            q.push({cx, cy, ck, 1 - cdaytime});
        }
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d], ndaytime = 1 - cdaytime;

            if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
            if (A[nx][ny] == 1) {
                if (ck == 0) continue;
                if (cdaytime == 0) continue; // 지금 밤이면 넘긴다.
                if (D[nx][ny][ck - 1][ndaytime] != 0) continue;
                D[nx][ny][ck - 1][ndaytime] = dist + 1;
                q.push({nx, ny, ck - 1, ndaytime});
            } else {
                if (D[nx][ny][ck][ndaytime] != 0) continue;
                D[nx][ny][ck][ndaytime] = dist + 1;
                q.push({nx, ny, ck, ndaytime});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
