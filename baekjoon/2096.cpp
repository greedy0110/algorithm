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

const int MS = 100000;
char board[MS][3];
int N;

void solve() {
    cin >> N;

    repeat(i, N) {
        cin >> board[i][0] >> board[i][1] >> board[i][2];
    }

    int max_r[3] = {board[N - 1][0] - '0', board[N - 1][1] - '0', board[N - 1][2] - '0'};
    int min_r[3] = {board[N - 1][0] - '0', board[N - 1][1] - '0', board[N - 1][2] - '0'};

    for (int i = N - 2; i >= 0; i--) {
        int cr_max[3];
        cr_max[0] = board[i][0] - '0' + max(max_r[0], max_r[1]);
        cr_max[1] = board[i][1] - '0' + max(max(max_r[0], max_r[1]), max_r[2]);
        cr_max[2] = board[i][2] - '0' + max(max_r[1], max_r[2]);
        for (int j = 0; j < 3; j++) max_r[j] = cr_max[j];

        int cr_min[3];
        cr_min[0] = board[i][0] - '0' + min(min_r[0], min_r[1]);
        cr_min[1] = board[i][1] - '0' + min(min(min_r[0], min_r[1]), min_r[2]);
        cr_min[2] = board[i][2] - '0' + min(min_r[1], min_r[2]);
        for (int j = 0; j < 3; j++) min_r[j] = cr_min[j];
    }

    cout << *max_element(all(max_r)) << " " << *min_element(all(min_r)) << endl;
}
