//
// Created by 신승민 on 2021/06/02.
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
typedef vector<vc> vvc;
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

int N, M;

const char WALL = '#';
const char HOLE = 'O';
const char RED = 'R';
const char BLUE = 'B';

const int SUCCESS = 1, ERROR = -1, DONE = 0;
const int FAIL = 1000;

// rx, ry, bx, by 는 한번 다시 위치할 필요가 없다.
int rb_cache[11][11][11][11] = {0};

void print_board(const vvc &board) {
    for (auto &row: board) {
        for (auto r: row) {
            printf("%c", r);
        }
        printf("\n");
    }
    printf("\n");
}

bool in_board(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

bool is_obs(const vvc &board, int x, int y) {
    char t = board[x][y];
    return t == WALL || t == HOLE || t == RED || t == BLUE;
}

pii find_ball(const vvc &board, char kind) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == kind) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

int valid(const vvc &board) {
    pii red = find_ball(board, RED);
    pii blue = find_ball(board, BLUE);

    if (blue.first == -1) {
        return ERROR;
    }

    if (red.first == -1) {
        return SUCCESS;
    }

    return DONE;
}

void move_ball(vvc &board, int x, int y, int dir) {
    int nx, ny;
    switch (dir) {
        case 0:
            // y-- 방향으로 붙는다.
            ny = y;
            while (!is_obs(board, x, ny - 1)) { ny--; }

            if (board[x][ny - 1] == HOLE) {
                // 0 을 만나면, 사라진다.
                board[x][y] = '.';
            } else {
                // #, RED, BLUE 을 만나면, 이동하지 못한다.
                char temp = board[x][y];
                board[x][y] = '.';
                board[x][ny] = temp;
            }
            break;
        case 1:
            // y++ 방향으로 붙는다.
            ny = y;
            while (!is_obs(board, x, ny + 1)) { ny++; }

            if (board[x][ny + 1] == HOLE) {
                // 0 을 만나면, 사라진다.
                board[x][y] = '.';
            } else {
                // #, RED, BLUE 을 만나면, 이동하지 못한다.
                char temp = board[x][y];
                board[x][y] = '.';
                board[x][ny] = temp;
            }
            break;
        case 2:
            // x-- 방향으로 붙는다.
            nx = x;
            while (!is_obs(board, nx - 1, y)) { nx--; }

            if (board[nx - 1][y] == HOLE) {
                // 0 을 만나면, 사라진다.
                board[x][y] = '.';
            } else {
                // #, RED, BLUE 을 만나면, 이동하지 못한다.
                char temp = board[x][y];
                board[x][y] = '.';
                board[nx][y] = temp;
            }
            break;
        case 3:
            // x++ 방향으로 붙는다.
            nx = x;
            while (!is_obs(board, nx + 1, y)) { nx++; }

            if (board[nx + 1][y] == HOLE) {
                // 0 을 만나면, 사라진다.
                board[x][y] = '.';
            } else {
                // #, RED, BLUE 을 만나면, 이동하지 못한다.
                char temp = board[x][y];
                board[x][y] = '.';
                board[nx][y] = temp;
            }
            break;
    }
}

vvc make_next(vvc board, int dir) {
    pii red = find_ball(board, RED);
    pii blue = find_ball(board, BLUE);

    if ((dir == 0 && (red.first == blue.first) && blue.second < red.second) ||
        (dir == 1 && (red.first == blue.first) && blue.second > red.second) ||
        (dir == 2 && (red.second == blue.second) && blue.first < red.first) ||
        (dir == 3 && (red.second == blue.second) && blue.first > red.first)
            ) {
        move_ball(board, blue.first, blue.second, dir);
        move_ball(board, red.first, red.second, dir);
    } else {
        move_ball(board, red.first, red.second, dir);
        move_ball(board, blue.first, blue.second, dir);
    }

    return board;
}

int p(vvc board, int cnt = 0) {
    if (cnt > 10) {
        return FAIL;
    }

    int vld = valid(board);

    if (vld == ERROR) {
        return FAIL;
    }
    if (vld == SUCCESS) {
        return cnt;
    }

    int ret = FAIL;
    for (int dir = 0; dir < 4; dir++) {
        ret = min(ret, p(make_next(board, dir), cnt + 1));
    }

    return ret;
}

int p_iter(vvc f) {
    queue<pair<vvc, int>> cap;
    cap.push(make_pair(f, 0));
    pii red = find_ball(f, RED);
    pii blue = find_ball(f, BLUE);
    rb_cache[red.first][red.second][blue.first][blue.second] = 1;

    while (!cap.empty()) {
        auto bb = cap.front();
        cap.pop();

        vvc &board = bb.first;
        int dist = bb.second;

        if (dist >= 10) return FAIL;

        for (int dir = 0; dir < 4; dir++) {
            vvc nextb = make_next(board, dir);
            pii nxtr = find_ball(nextb, RED);
            pii nxtb = find_ball(nextb, BLUE);
            int vld = valid(nextb);
            if (vld == SUCCESS) return dist + 1;
            if (vld == ERROR) continue;

            int &rb = rb_cache[nxtr.first][nxtr.second][nxtb.first][nxtb.second];
            if (rb != 0) continue;
            rb = 1;

            cap.push(make_pair(nextb, dist + 1));
        }
    }

    return FAIL;
}

void solve() {
    scanf("%d %d", &N, &M);
    vvc board(N, vc(M));
    for (int x = 0; x < N; x++) {
        char buf[11];
        scanf("%s", buf);
        for (int y = 0; y < M; y++) {
            board[x][y] = buf[y];
        }
    }

//    print_board(board);
//    pii ball = find_ball(board, RED);
//    pii blue = find_ball(board, BLUE);
//    move_ball(board, ball.first, ball.second, 0);
//    ball = find_ball(board, RED);
//    move_ball(board, ball.first, ball.second, 3);
//    ball = find_ball(board, RED);
//    move_ball(board, ball.first, ball.second, 1);
//    ball = find_ball(board, RED);
//    move_ball(board, ball.first, ball.second, 3);
//    ball = find_ball(board, RED);
//    move_ball(board, ball.first, ball.second, 0);
//    print_board(board);

    int ret = p_iter(board);
    printf("%d\n", ret == FAIL ? -1 : ret);
}
