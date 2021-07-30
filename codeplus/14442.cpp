//
// Created by 신승민 on 2021/07/31.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

struct Vertex {
    int x;
    int y;
    int k;
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vvi A(N, vi(M));
    vector<vvi> D(N, vvi(M, vector<int>(K + 1, -1)));

    RP(i, N) {
        string temp;
        cin >> temp;
        RP(j, M) {
            A[i][j] = temp[j] - '0';
        }
    }

    queue<Vertex> q;
    D[0][0][K] = 1;
    q.push({0, 0, K});

    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int ck = q.front().k;
        int dist = D[cx][cy][ck];
        q.pop();

        if (cx == N - 1 && cy == M - 1) {
            cout << dist << endl;
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];

            if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;

            if (A[nx][ny] == 0) {
                if (D[nx][ny][ck] != -1) continue;

                D[nx][ny][ck] = dist + 1;
                q.push({nx, ny, ck});
            } else {
                if (ck == 0) continue;
                if (D[nx][ny][ck - 1] != -1) continue;

                D[nx][ny][ck - 1] = dist + 1;
                q.push({nx, ny, ck - 1});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
