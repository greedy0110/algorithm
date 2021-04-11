//
// Created by 신승민 on 2021/04/11.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <queue>
#include <numeric>
#include <set>
#include <map>

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

void printvi(const vi &v, string deli = " ") {
    for (auto i : v) {
        cout << i << deli;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

int R, C;
int board[51][51];
int spread[51][51];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int clean_top = -1;
int clean_bottom;

bool in_board(int r, int c) {
    return 1 <= r && r <= R && 1 <= c && c <= C;
}

void spread_dust() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            spread[r][c] = 0;
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {

            int consume = 0;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (!in_board(nr, nc)) continue;
                if (board[nr][nc] == -1) continue;

                int factor = board[r][c] / 5;
                spread[nr][nc] += factor;
                consume += factor;
            }
            spread[r][c] -= consume;
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            board[r][c] += spread[r][c];
        }
    }
}

void cleaning() {
    int prev_dust = -1;
    for (int c = 2; c <= C; c++) {
        if (prev_dust == -1) {
            prev_dust = board[clean_top][c];
            board[clean_top][c] = 0;
        } else {
            int temp = board[clean_top][c];
            board[clean_top][c] = prev_dust;
            prev_dust = temp;
        }
    }

    for (int r = clean_top - 1; r >= 1; r--) {
        int temp = board[r][C];
        board[r][C] = prev_dust;
        prev_dust = temp;
    }

    for (int c = C - 1; c >= 1; c--) {
        int temp = board[1][c];
        board[1][c] = prev_dust;
        prev_dust = temp;
    }

    for (int r = 2; r < clean_top; r++) {
        int temp = board[r][1];
        board[r][1] = prev_dust;
        prev_dust = temp;
    }

    prev_dust = -1;
    for (int c = 2; c <= C; c++) {
        if (prev_dust == -1) {
            prev_dust = board[clean_bottom][c];
            board[clean_bottom][c] = 0;
        } else {
            int temp = board[clean_bottom][c];
            board[clean_bottom][c] = prev_dust;
            prev_dust = temp;
        }
    }

    for (int r = clean_bottom + 1; r <= R; r++) {
        int temp = board[r][C];
        board[r][C] = prev_dust;
        prev_dust = temp;
    }

    for (int c = C - 1; c >= 1; c--) {
        int temp = board[R][c];
        board[R][c] = prev_dust;
        prev_dust = temp;
    }

    for (int r = R - 1; r > clean_bottom; r--) {
        int temp = board[r][1];
        board[r][1] = prev_dust;
        prev_dust = temp;
    }
}

void print_board() {
    cout << "####" << endl;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
    cout << "####" << endl;
}

int total_dust() {
    int ret = 0;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (board[r][c] > 0) ret += board[r][c];
        }
    }
    return ret;
}

void solve() {
    int t;
    cin >> R >> C >> t;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> board[r][c];

            if (board[r][c] == -1) {
                if (clean_top == -1) {
                    clean_top = r;
                } else {
                    clean_bottom = r;
                }
            }
        }
    }

    repeat(_, t) {
        spread_dust();
        cleaning();
    }

    cout << total_dust() << endl;
}