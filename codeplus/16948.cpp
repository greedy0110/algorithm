//
// Created by 신승민 on 2021/08/01.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, x1, y1, x2, y2;
    cin >> N >> x1 >> y1 >> x2 >> y2;

    vvi D(N, vi(N, -1));
    queue<pair<int, int>> q;
    D[x1][y1] = 0;
    q.push({x1, y1});

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int d = 0; d < 6; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];

            if (nx < 0 || N <= nx || ny < 0 || N <= ny) continue;
            if (D[nx][ny] != -1) continue;

            D[nx][ny] = D[cx][cy] + 1;
            q.push({nx, ny});
        }
    }

    cout << D[x2][y2] << endl;

    return 0;
}
