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

    const int MOD = 1000000000;

    int D[201][201] = {};
    int N, K;
    cin >> N >> K;

    D[0][0] = 1;
    for (int i = 0; i <= N; i++) {
        for (int k = 1; k <= K; k++) {
            for (int j = 0; j <= i; j++) {
                D[i][k] += D[i - j][k - 1];
                D[i][k] %= MOD;
            }
        }
    }
    cout << D[N][K] << endl;

    return 0;
}
