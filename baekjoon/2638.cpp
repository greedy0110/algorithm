//
// Created by 신승민 on 2021/04/10.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <queue>
#include <numeric>
#include <set>

using namespace std;

#define all(X) begin((X)), end((X))
#define endl '\n'
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define repeat(i, X) for (int i=0; i<((X)); i++)
#define BIG 987654321
#define SUPER_BIG 987654321123456789

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
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

// 0 -> 내부 공기
// 1 -> 치즈
// 2 -> 외부 공기
// 3 -> 제거될 친구
int board[101][101] = {0,};
int N, M;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int remain_cheese;
int hours = 0;

bool in_board(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

void get_fresh_air_in() {
    queue<pii> q;
    vector<vb> visited(N, vb(M, false));

    repeat(i, N) {
        q.push(make_pair(i, 0));
        q.push(make_pair(i, M - 1));

        visited[i][0] = true;
        visited[i][M - 1] = true;
    }

    repeat(i, M) {
        q.push(make_pair(0, i));
        q.push(make_pair(N - 1, i));

        visited[0][i] = true;
        visited[N - 1][i] = true;
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        board[x][y] = 2;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!in_board(nx, ny)) continue;
            if (visited[nx][ny]) continue;

            if (board[nx][ny] != 1) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

void melt_cheese() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (board[x][y] != 1) continue;

            int outdoor = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!in_board(nx, ny)) continue;

                if (board[nx][ny] == 2) outdoor++;
            }

            if (outdoor >= 2) {
                board[x][y] = 3;
            }
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (board[x][y] == 3) {
                remain_cheese--;
                board[x][y] = 2;
            }
        }
    }

    hours++;
}

void solve() {
    cin >> N >> M;

    repeat(x, N) {
        repeat(y, M) {
            cin >> board[x][y];
            if (board[x][y] == 1) remain_cheese++;
        }
    }

    hours = 0;
    while (remain_cheese != 0) {
        get_fresh_air_in();
        melt_cheese();
    }

    cout << hours << endl;
}