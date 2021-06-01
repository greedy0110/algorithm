//
// Created by 신승민 on 2021/06/01.
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

int N;
const int EMPTY = 0;

void print_board(const vvi &board) {
    for (auto &row: board) {
        for (auto r: row) {
            printf("%d ", r);
        }
        printf("\n");
    }
    printf("\n");
}

void compress_up(vvi &board) {
    for (int y = 0; y < N; y++) {
        vb comp = vb(N, false);
        for (int x = 1; x < N; x++) {
            if (board[x][y] != EMPTY) {
                int k = 0;
                while (k < x && board[k][y] != EMPTY) {
                    k++;
                }
                assert(k == x || board[k][y] == EMPTY);

                if (k != 0 && board[k - 1][y] == board[x][y] && !comp[k - 1]) {
                    comp[k - 1] = true;
                    board[k - 1][y] += board[x][y];
                    board[x][y] = 0;
                    continue;
                }

                int temp = board[x][y];
                board[x][y] = 0;
                board[k][y] = temp;
            }
        }
    }
}

void compress_down(vvi &board) {
    reverse(all(board));
    compress_up(board);
    reverse(all(board));
}

void compress_left(vvi &board) {
    for (int x = 0; x < N; x++) {
        vb comp = vb(N, false);
        for (int y = 1; y < N; y++) {
            if (board[x][y] != EMPTY) {
                int k = 0;
                while (k < y && board[x][k] != EMPTY) {
                    k++;
                }
                assert(k == y || board[x][k] == EMPTY);

                if (k != 0 && board[x][k - 1] == board[x][y] && !comp[k - 1]) {
                    comp[k - 1] = true;
                    board[x][k - 1] += board[x][y];
                    board[x][y] = 0;
                    continue;
                }

                int temp = board[x][y];
                board[x][y] = 0;
                board[x][k] = temp;
            }
        }
    }
}

void compress_right(vvi &board) {
    for (int x = 0; x < N; x++) reverse(all(board[x]));
    compress_left(board);
    for (int x = 0; x < N; x++) reverse(all(board[x]));
}

void p(vvi board, int &ret, int k = 0) {
    int local_max = -1;
    for (int i = 0; i < N; i++) {
        local_max = max(local_max, *max_element(all(board[i])));
    }
    ret = max(ret, local_max);

    if (k == 5) {
        return;
    }

    vvi left = board;
    compress_left(left);
    vvi right = board;
    compress_right(right);
    vvi up = board;
    compress_up(up);
    vvi down = board;
    compress_down(down);

    k++;
    p(left, ret, k);
    p(right, ret, k);
    p(up, ret, k);
    p(down, ret, k);
}

void solve() {
    scanf("%d", &N);

    vvi board(N, vi(N));

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            scanf("%d", &board[x][y]);
        }
    }

    int ret = -1;
    p(board, ret);
    printf("%d\n", ret);
}
