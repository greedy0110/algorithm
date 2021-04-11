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

int board[20][20];
int cache[20][20][3];
int N;

bool in_board(int x, int y) {
    return 1 <= x && x <= N && 1 <= y && y <= N;
}

int move(int x, int y, int state) {
    if (x == N && y == N) return 1;

    int &ans = cache[x][y][state];

    if (ans != -1) return ans;

    int rx = x;
    int ry = y + 1;

    int bx = x + 1;
    int by = y;

    int cx = x + 1;
    int cy = y + 1;

    bool ra = in_board(rx, ry) && board[rx][ry] == 0;
    bool ba = in_board(bx, by) && board[bx][by] == 0;
    bool ca = in_board(cx, cy) && board[cx][cy] == 0;

    int cc = 0;
    if (ra && ba && ca) {
        cc = move(cx, cy, 1);
    }

    int rc = 0;
    if (state != 2 && ra) {
        rc = move(rx, ry, 0);
    }

    int bc = 0;
    if (state != 0 && ba) {
        bc = move(bx, by, 2);
    }

    return ans = cc + rc + bc;
}

void solve() {
    cin >> N;

    repeat(x, N) {
        repeat(y, N) {
            cin >> board[x + 1][y + 1];
            repeat(i, 3) {
                cache[x + 1][y + 1][i] = -1;
            }
        }
    }

    cout << move(1, 2, 0) << endl;
}
