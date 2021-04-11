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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

vvi combinations(int n, int k) {
    vvi ret;
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = i + 1; j < n - k + 2; j++) {
            for (int z = j + 1; z < n; z++) {
                vi candi;
                candi.push_back(i);
                candi.push_back(j);
                candi.push_back(z);
                ret.push_back(candi);
            }
        }
    }

    return ret;
}

int N, M;
int board[9][9];
int temp_board[9][9];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool in_board(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

int spread_virus() {
    queue<pair<int, int>> q;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (temp_board[x][y] == 2)
                q.push(make_pair(x, y));
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!in_board(nx, ny)) continue;

            if (temp_board[nx][ny] == 0) {
                temp_board[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }

    int size_safe = 0;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (temp_board[x][y] == 0)
                size_safe++;
        }
    }

    return size_safe;
}

void solve() {
    cin >> N >> M;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cin >> board[x][y];
        }
    }

    int ret = -1;
    for (auto &com : combinations(N * M, 3)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                temp_board[i][j] = board[i][j];
            }
        }

        bool trigger = true;
        for_each(all(com), [&](auto it) {
            if (temp_board[it / M][it % M] != 0) {
                trigger = false;

            }
            temp_board[it / M][it % M] = 1;
        });
        if (!trigger) continue;

        ret = max(ret, spread_virus());
    }

    cout << ret << endl;
}
