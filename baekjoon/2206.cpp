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

char board[1001][1001];
bool visited[1001][1001][2];
int N, M;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool in_board(int x, int y) {
    return 1 <= x && x <= N && 1 <= y && y <= M;
}

class Factor {
public:
    int x;
    int y;
    int dist;
    int hammer;
};

void p_bfs() {
    queue<Factor> q;

    Factor st{1, 1, 1, 1};
    visited[1][1][1] = true;

    q.push(st);

    vi ans;
    while (!q.empty()) {
        Factor cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int dist = cur.dist;
        int hammer = cur.hammer;

        if (x == N && y == M) {
            ans.push_back(dist);
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!in_board(nx, ny)) continue;
            if (visited[nx][ny][hammer]) continue;

            if (board[nx][ny] == '0') {
                Factor next{nx, ny, dist + 1, hammer};
                visited[nx][ny][hammer] = true;
                q.push(next);
            } else if (hammer >= 1) {
                Factor next{nx, ny, dist + 1, hammer - 1};
                visited[nx][ny][hammer - 1] = true;
                q.push(next);
            }
        }
    }

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        auto ret_iter = min_element(all(ans));
        cout << *ret_iter << endl;
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        char row[M];
        cin >> row;
        for (int j = 1; j <= M; j++) {
            visited[i][j][0] = false;
            visited[i][j][1] = false;
            board[i][j] = row[j - 1];
        }
    }

    p_bfs();
}

// 재귀 알고리즘을 짜는 경우, 재귀 depth 를 알아볼 것...
