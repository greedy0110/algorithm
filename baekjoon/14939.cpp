//
// Created by 신승민 on 2021/04/12.
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

bool board[11][11];
bool original[11][11];
int N = 10;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool in_board(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

vvi candidate;

void combination(vi &ret, int k, int last = -1) {
    if (ret.size() == k) {
        candidate.push_back(ret);
        return;
    }

    for (int i = last + 1; i < N; i++) {
        ret.push_back(i);
        combination(ret, k, i);
        ret.pop_back();
    }
}

void restore() {
    repeat(x, 10) {
        repeat(y, 10) {
            board[x][y] = original[x][y];
        }
    }
}

// [0, x-1] 영역은 전부다 처리가 완료된 상태라고 가정한다.
// 따라서 이 함수가 종료되었을 때
// [0, x-1] 영역은 전부 false 이 되어야 한다. 그러지 못한다면 끝!
int p(int x) {
    if (x == N) {
        repeat(y, N) {
            // 불가능한 케이스
            if (board[x - 1][y]) {
                return BIG;
            }
        }
        return 0;
    }

    int count = 0;
    repeat(y, N) {
        if (board[x - 1][y]) {
            // 눌러야함.
            count++;

            repeat(i, 4) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!in_board(nx, ny)) continue;
                board[nx][ny] = !board[nx][ny];
            }
            board[x][y] = !board[x][y];
        }
    }

    repeat(y, N) {
        // 불가능한 케이스
        if (board[x - 1][y]) {
            return BIG;
        }
    }

    return count + p(x + 1);
}

void solve() {
    repeat(x, 10) {
        repeat(y, 10) {
            char s;
            cin >> s;
            original[x][y] = s == 'O';
        }
    }

    for (int k = 0; k <= N; k++) {
        vi ret;
        combination(ret, k);
    }

    int ans = BIG;
    for (auto &first_row: candidate) {
        restore();

        int init_count = first_row.size();
        for (auto y: first_row) {
            // y 들을 다 누른 상태로
            repeat(i, 4) {
                int nx = dx[i];
                int ny = y + dy[i];

                if (!in_board(nx, ny)) continue;
                board[nx][ny] = !board[nx][ny];
            }
            board[0][y] = !board[0][y];
        }

        int count = p(1);

        ans = min(ans, init_count + count);
    }

    cout << ((ans >= BIG) ? -1 : ans) << endl;
}
