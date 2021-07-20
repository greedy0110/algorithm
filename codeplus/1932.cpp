//
// Created by 신승민 on 2021/07/20.
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

    int D[501][501] = {};
    int A[501][501] = {};
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> A[i][j];
        }
    }

    D[1][1] = A[1][1];
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            D[i][j] = max(D[i - 1][j - 1], D[i - 1][j]) + A[i][j];
        }
    }

    int ans = D[N][1];
    for (int j = 2; j <= N; j++) {
        ans = max(ans, D[N][j]);
    }
    cout << ans << endl;

    return 0;
}
