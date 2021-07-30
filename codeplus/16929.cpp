//
// Created by 신승민 on 2021/07/30.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int N, M;
char G[50][50];
vector<vector<int>> D;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool dfs(int sx, int sy, int fx, int fy, char color) {
    for (int d = 0; d < 4; d++) {
        int nx = sx + dx[d], ny = sy + dy[d];

        if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
        if (nx == fx && ny == fy) continue;
        if (G[nx][ny] != color) continue;
        if (D[nx][ny] != -1) return true;

        D[nx][ny] = D[sx][sy] + 1;
        if (dfs(nx, ny, sx, sy, color)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    RP(i, N) {
        string temp;
        cin >> temp;
        RP(j, M) {
            G[i][j] = temp[j];
        }
    }

    D = vector<vector<int>>(N, vector<int>(M, -1));

    RP(i, N) {
        RP(j, M) {
            if (D[i][j] != -1) continue;
            D[i][j] = 0;
            if (dfs(i, j, -1, -1, G[i][j])) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
