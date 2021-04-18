//
// Created by 신승민 on 2021/04/18.
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

vector<vector<char>> board;
vector<vb> visited;
int H, W;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool in_board(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

void unlock_door(const set<char> &keys) {
    repeat(x, H) {
        repeat(y, W) {
            // 획득한 열쇠는 필요가 없다.
            if (keys.find(board[x][y]) != keys.end()) {
                board[x][y] = '.';
            }

            // key 로 열수 있는 문은 의미가 없어진다.
            // 'a' - 'A' == key - door
            // key == 'a' - 'A' + door
            if (keys.find(board[x][y] + 'a' - 'A') != keys.end()) {
                board[x][y] = '.';
            }
        }
    }
}

bool is_key(int x, int y) {
    return 'a' <= board[x][y] && board[x][y] <= 'z';
}

bool through(int x, int y) {
    // 빈 공간, 문을 통해서만 이동할 수 있다고 한다.
//    return board[x][y] == '.';
    return board[x][y] == '.' || board[x][y] == '$' || is_key(x, y);
}

set<pii> find_start_point() {
    set<pii> sp;
    repeat(x, H) {
        if (through(x, 0)) {
            sp.insert(make_pair(x, 0));
        }
        if (through(x, W - 1)) {
            sp.insert(make_pair(x, W - 1));
        }
    }

    repeat(y, W) {
        if (through(0, y)) {
            sp.insert(make_pair(0, y));
        }
        if (through(H - 1, y)) {
            sp.insert(make_pair(H - 1, y));
        }
    }

    return sp;
}

int search() {

    while (true) {
        // 열쇠를 찾고 열쇠 찾은게 없다면, 반복 종료.
        // 열쇠를 찾았다면, 모든 문을 열고 다시 반복.
        visited = vector<vb>(H, vb(W, false));

        // 다시, 건물 밖에서 열 수 있는 문이 추가되었을 수 있다.
        auto start_points = find_start_point();

        set<char> found_keys;
        int num_found_doc = 0;

        queue<pii> q;
        for (auto &sp : start_points) {
            int sx = sp.first, sy = sp.second;
            q.push(make_pair(sx, sy));
            visited[sx][sy] = true;

            if (board[sx][sy] == '$') {
                num_found_doc++;
            }
        }

        while (!q.empty()) {
            auto value = q.front();
            q.pop();

            int x = value.first;
            int y = value.second;

            repeat(i, 4) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!in_board(nx, ny)) continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = true;

                if (board[nx][ny] == '.') {
                    q.push(make_pair(nx, ny));
                } else if (board[nx][ny] == '$') {
                    num_found_doc++;
                    q.push(make_pair(nx, ny));
                } else if (is_key(nx, ny)) {
                    found_keys.insert(board[nx][ny]);
                    q.push(make_pair(nx, ny));
                }
            }
        }

        if (found_keys.empty()) {
            return num_found_doc;
        }

        unlock_door(found_keys);
    }
}

void solve() {
    int c;
    cin >> c;
    while (c--) {
        cin >> H >> W;

        board = vector<vector<char>>(H, vector<char>(W));
        visited = vector<vb>(H, vb(W, false));

        repeat(x, H) {
            repeat(y, W) {
                cin >> board[x][y];
            }
        }

        string key;
        cin >> key;
        if (key != "0") {
            set<char> keys;
            for (auto c: key) {
                keys.insert(c);
            }
            unlock_door(keys);
        }

        cout << search() << endl;
    }
}
