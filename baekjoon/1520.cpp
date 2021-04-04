//
// Created by 신승민 on 2021/04/04.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vlli;

int M, N;
vvi cache = vvi(501, vi(501, -1));
vvi board = vvi(501, vi(501, 0));

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool in_board(int y, int x) {
    return 1 <= y && y <= M && 1 <= x && x <= N;
}

int route(int y, int x) {
    if (y == M && x == N) return 1;

    int &ans = cache[y][x];
    if (ans != -1) return ans;

    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (in_board(ny, nx) && board[ny][nx] < board[y][x])
            ret += route(ny, nx);
    }

    return ans = ret;
}

int main() {
    cin >> M >> N;
    for (int y = 1; y <= M; y++)
        for (int x = 1; x <= N; x++)
            cin >> board[y][x];

    cout << route(1, 1) << endl;

    return 0;
}
