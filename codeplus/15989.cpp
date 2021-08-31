//
// Created by 신승민 on 2021/08/31.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'
#define custom_pq(X) priority_queue<X, vector<X>, X>

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

int d[10001][4] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    d[1][1] = 1;
    d[1][2] = 0;
    d[1][3] = 0;

    d[2][1] = 1;
    d[2][2] = 1;
    d[2][3] = 0;

    d[3][1] = 1;
    d[3][2] = 1;
    d[3][3] = 1;

    for (int i = 4; i <= 10000; i++) {
        for (int last = 1; last <= 3; last++) {
            for (int nxt = last; nxt >= 1; nxt--) {
                d[i][last] += d[i - last][nxt];
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << d[N][1] + d[N][2] + d[N][3] << endl;
    }

    return 0;
}
