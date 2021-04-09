//
// Created by 신승민 on 2021/04/09.
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

const int MAXH = 3072;
bool board[2 * MAXH][2 * MAXH] = {false,};

void paint(int x, int y, int height) {
    if (height == 3) {
        board[x][y] = true;
        board[x - 1][y + 1] = true;
        board[x + 1][y + 1] = true;
        for (int i = 0; i < 5; i++) {
            board[x - 2 + i][y + 2] = true;
        }
        return;
    }

    int lx = (2 * x + height) / 2;
    int rx = (2 * x - height) / 2;
    int ny = (height / 2 + y);

    height /= 2;
    paint(x, y, height);
    paint(lx, ny, height);
    paint(rx, ny, height);
}

void solve() {
    int N;
    cin >> N;

    paint(N - 1, 0, N);

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < 2 * N - 1; x++) {
            if (board[x][y]) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}
