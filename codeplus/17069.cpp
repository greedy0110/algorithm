//
// Created by 신승민 on 2021/07/31.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    int A[32][32];
    ll D[32][32][3] = {};
    RP(i, N) RP(j, N) cin >> A[i][j];

    D[0][1][0] = 1;
    for (int y = 2; y < N; y++) {
        D[0][y][0] = D[0][y - 1][0];
        if (A[0][y] == 1) D[0][y][0] = 0;
    }

    for (int y = 2; y < N; y++) {
        for (int x = 1; x < N; x++) {
            if (A[x][y] == 1) continue;
            D[x][y][0] = D[x][y - 1][0] + D[x][y - 1][2];
            D[x][y][1] = D[x - 1][y][1] + D[x - 1][y][2];

            if (A[x - 1][y] == 1 || A[x][y - 1] == 1) continue;
            D[x][y][2] = D[x - 1][y - 1][0] + D[x - 1][y - 1][1] + D[x - 1][y - 1][2];
        }
    }

    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        ans += D[N - 1][N - 1][i];
    }

    cout << ans << endl;

    return 0;
}
