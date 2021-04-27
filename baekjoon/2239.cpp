//
// Created by 신승민 on 2021/04/27.
//

#include <bits/stdc++.h>

using namespace std;

#define all(X) begin((X)), end((X))
#define endl '\n'
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define repeat(i, X) for (int i=0; i<((X)); i++)
#define BIG 100000007
#define SUPER_BIG 987654321123456789

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
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

int N = 9;
int board[10][10] = {};

// find all possibilities given index.
bool p(int index) {
    if (index == 81) return true;

    int sx = index / N;
    int sy = index % N;

    if (board[sx][sy] != 0) return p(index + 1);

    vb checked(10, false);

    for (int x = sx / 3 * 3; x < sx / 3 * 3 + 3; x++) {
        for (int y = sy / 3 * 3; y < sy / 3 * 3 + 3; y++) {
            checked[board[x][y]] = true;
        }
    }

    for (int y = 0; y < N; y++) {
        checked[board[sx][y]] = true;
    }

    for (int x = 0; x < N; x++) {
        checked[board[x][sy]] = true;
    }

    vi possibles;
    for (int i = 1; i < 10; i++) {
        if (!checked[i]) possibles.push_back(i);
    }

    if (possibles.empty()) return false;

    for (int possible : possibles) {
        board[sx][sy] = possible;
        if (p(index + 1)) return true;
        board[sx][sy] = 0;
    }

    return false;
}

void solve() {
    repeat(i, N) {
        repeat(j, N) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }

    p(0);

    repeat(i, N) {
        repeat(j, N) {
            cout << board[i][j];
        }
        cout << endl;
    }
}
