//
// Created by 신승민 on 2021/07/19.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int MOD = 9901;
    int D[100001][3] = {};
    RP(i, 3) D[1][i] = 1;
    int N;
    cin >> N;
    for (int i = 2; i <= N; i++) {
        D[i][0] = D[i - 1][0] + D[i - 1][1] + D[i - 1][2];
        D[i][1] = D[i - 1][0] + D[i - 1][2];
        D[i][2] = D[i - 1][0] + D[i - 1][1];

        D[i][0] %= MOD;
        D[i][1] %= MOD;
        D[i][2] %= MOD;
    }

    cout << (D[N][0] + D[N][1] + D[N][2]) % MOD << endl;

    return 0;
}
