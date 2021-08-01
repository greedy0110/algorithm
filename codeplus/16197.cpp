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

int N, M;
char B[20][20];

bool in_board(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

struct Point {
    int x;
    int y;

    bool operator==(const Point &other) {
        return x == other.x && y == other.y;
    }

    bool none() {
        return x < 0 || N <= x || y < 0 || M <= y;
    }
};

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int go(Point cp1, Point cp2, int depth) {
    if (depth > 10) return -1;
    if (cp1 == cp2) return -1;
    if (cp1.none() && cp2.none()) return -1;
    if (cp1.none() || cp2.none()) return depth;

    int ans = 100;
    for (int d = 0; d < 4; d++) {
        Point ncp1{}, ncp2{};

        int nx1 = cp1.x + dx[d], ny1 = cp1.y + dy[d];
        if (in_board(nx1, ny1) && B[nx1][ny1] == '#') {
            ncp1 = cp1;
        } else {
            ncp1 = {nx1, ny1};
        }

        int nx2 = cp2.x + dx[d], ny2 = cp2.y + dy[d];
        if (in_board(nx2, ny2) && B[nx2][ny2] == '#') {
            ncp2 = cp2;
        } else {
            ncp2 = {nx2, ny2};
        }

        int ret = go(ncp1, ncp2, depth + 1);
        if (ret != -1) ans = min(ans, ret);
    }

    if (ans == 100) return -1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    vector<Point> coins;
    RP(x, N) {
        string temp;
        cin >> temp;
        RP(y, M) {
            B[x][y] = temp[y];

            if (B[x][y] == 'o') {
                B[x][y] = '.';
                coins.push_back({x, y});
            }
        }
    }

    int ans = go(coins[0], coins[1], 0);
    cout << ans << endl;

    return 0;
}
