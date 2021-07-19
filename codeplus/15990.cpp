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

    const long long MOD = 1000000009;
    const int P = 100000;
    long long D[P + 1][4] = {};
    for (int i = 1; i <= P; i++) {
        if (i >= 1) {
            D[i][1] = D[i - 1][2] + D[i - 1][3];
            if (i == 1) D[i][1] = 1;
        }
        if (i >= 2) {
            D[i][2] = D[i - 2][1] + D[i - 2][3];
            if (i == 2) D[i][2] = 1;
        }
        if (i >= 3) {
            D[i][3] = D[i - 3][1] + D[i - 3][2];
            if (i == 3) D[i][3] = 1;
        }
        D[i][1] %= MOD;
        D[i][2] %= MOD;
        D[i][3] %= MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (D[n][1] + D[n][2] + D[n][3]) % MOD << endl;
    }

    return 0;
}
