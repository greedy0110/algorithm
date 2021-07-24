//
// Created by 신승민 on 2021/07/24.
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

    int T;
    cin >> T;
    while (T--) {
        int D[1001][1001];
        int N;
        cin >> N;
        RP(i, N) cin >> D[i][i];
        int P[1002];
        P[0] = 0;
        P[1] = D[0][0];
        for (int i = 2; i <= N; i++) {
            P[i] = P[i - 1] + D[i - 1][i - 1];
        }

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < N - i; j++) {
                int sum = 0;
                for (int k = j; k <= i + j; k++) sum += D[k][k];

                D[j][i + j] = P[i + j + 1] - P[j] - min(D[j][i + j - 1], D[j + 1][i + j]);
            }
        }

        cout << D[0][N - 1] << endl;
    }


    return 0;
}
