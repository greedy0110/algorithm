//
// Created by 신승민 on 2021/04/08.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <map>

using namespace std;

#define all(X) begin((X)), end((X))
#define sz(X) (int)(X).size()
#define fi first
#define endl '\n'
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define BIG 987654321

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<string> vs;
typedef priority_queue<int, vi, greater<>> mq;
typedef priority_queue<pii, vpii, greater<>> mpq;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

int cache[1001][1001][2];
char board[1001][1001];
bool visited[1001][1001];
int N, M;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool in_board(int x, int y) {
    return 1 <= x && x <= N && 1 <= y && y <= M;
}

int p(int x, int y, int z) {
    if (x == N && y == M) return 1;

    int &ans = cache[x][y][z];

    if (ans != -1) return ans;

    int ret = BIG;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!in_board(nx, ny)) continue;
        if (visited[nx][ny]) continue;

        if (board[nx][ny] == '0') {
            visited[nx][ny] = true;
            ret = min(ret, 1 + p(nx, ny, z));
            visited[nx][ny] = false;
        } else if (z == 1) {
            visited[nx][ny] = true;
            ret = min(ret, 1 + p(nx, ny, z - 1));
            visited[nx][ny] = false;
        }
    }

    return ans = ret;
}

void solve() {
//    cin >> N >> M;
    N = M = 1000;
    for (int i = 1; i <= N; i++) {
        char row[M];
//        cin >> row;
        for (int j = 1; j <= M; j++) {
            cache[i][j][0] = -1;
            cache[i][j][1] = -1;
            visited[i][j] = false;
//            board[i][j] = row[j - 1];
            board[i][j] = '0';
        }
    }

    visited[1][1] = true;
    int ans = p(1, 1, 1);
    cout << ((ans == BIG) ? -1 : ans) << endl;
}

// 재귀 알고리즘을 짜는 경우, 재귀 depth 를 알아볼 것...
