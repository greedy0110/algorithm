//
// Created by 신승민 on 2021/07/30.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

struct Node {
    int x;
    int y;
    int drill;
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, N;
    cin >> M >> N;
    int A[101][101];
    RP(i, N) {
        string temp;
        cin >> temp;
        RP(j, M) {
            A[i][j] = temp[j] - '0';
        }
    }

    vector<vector<int>> D(N, vector<int>(M, -1));
    deque<pair<int, int>> dq;
    D[0][0] = 0;
    dq.push_front({0, 0});

    while (!dq.empty()) {
        int cx = dq.front().first;
        int cy = dq.front().second;
        int dist = D[cx][cy];
        dq.pop_front();

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];

            if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
            if (D[nx][ny] != -1)continue;

            D[nx][ny] = dist + A[nx][ny];
            if (A[nx][ny] == 0) {
                dq.push_front({nx, ny});
            } else {
                dq.push_back({nx, ny});
            }
        }
    }

    cout << D[N - 1][M - 1] << endl;

    return 0;
}
