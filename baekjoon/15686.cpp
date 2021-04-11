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

vvi board;
vvpii chh;
vector<vb> visited;
int N, M;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void combinations(vpii &ret, int k, int lx = 0, int ly = 0) {
    if (ret.size() == k) {
        chh.push_back(ret);
        return;
    }

    for (int x = lx; x < N; x++) {
        int y = 0;
        if (x == lx) y = ly;
        for (y = 0; y < N; y++) {
            if (visited[x][y]) continue;
            if (board[x][y] != 2) continue;
            visited[x][y] = true;
            ret.push_back(make_pair(x, y));
            combinations(ret, k, x, y);
            ret.pop_back();
            visited[x][y] = false;
        }
    }
}

void solve() {
    cin >> N >> M;

    board = vvi(N, vi(N));
    visited = vector<vb>(N, vb(N, false));
    vpii homes;

    repeat(x, N) {
        repeat(y, N) {
            cin >> board[x][y];
            if (board[x][y] == 1) homes.push_back(make_pair(x, y));
        }
    }

    vpii ret;
    for (int i = 1; i <= M; i++) {
        combinations(ret, i);
    }

    int ans = BIG;
    for (auto &c : chh) {
        int total_dist = 0;
        for (auto &home : homes) {
            int chick_dist = BIG;
            for (auto &chicken : c) {
                chick_dist = min(chick_dist, abs(home.first - chicken.first) + abs(home.second - chicken.second));
            }
            total_dist += chick_dist;
        }
        ans = min(ans, total_dist);
    }

    cout << ans << endl;
}
