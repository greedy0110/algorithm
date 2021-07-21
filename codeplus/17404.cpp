//
// Created by 신승민 on 2021/07/21.
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

    int C[1001][3];
    int N;
    cin >> N;
    RP(i, N) cin >> C[i][0] >> C[i][1] >> C[i][2];

    //0번 고정.
    int D[1001][3];
    D[0][0] = C[0][0];
    D[0][1] = D[0][2] = 1000 * 1000 + 1;
    for (int i = 1; i < N; i++) {
        D[i][0] = min(D[i - 1][1], D[i - 1][2]) + C[i][0];
        D[i][1] = min(D[i - 1][0], D[i - 1][2]) + C[i][1];
        D[i][2] = min(D[i - 1][1], D[i - 1][0]) + C[i][2];
    }
    int ans = min(D[N - 1][1], D[N - 1][2]);

    //1번 고정.
    D[0][1] = C[0][1];
    D[0][0] = D[0][2] = 1000 * 1000 + 1;
    for (int i = 1; i < N; i++) {
        D[i][0] = min(D[i - 1][1], D[i - 1][2]) + C[i][0];
        D[i][1] = min(D[i - 1][0], D[i - 1][2]) + C[i][1];
        D[i][2] = min(D[i - 1][1], D[i - 1][0]) + C[i][2];
    }
    ans = min(ans, D[N - 1][0]);
    ans = min(ans, D[N - 1][2]);

    //2 고정.
    D[0][2] = C[0][2];
    D[0][0] = D[0][1] = 1000 * 1000 + 1;
    for (int i = 1; i < N; i++) {
        D[i][0] = min(D[i - 1][1], D[i - 1][2]) + C[i][0];
        D[i][1] = min(D[i - 1][0], D[i - 1][2]) + C[i][1];
        D[i][2] = min(D[i - 1][0], D[i - 1][1]) + C[i][2];
    }
    ans = min(ans, D[N - 1][0]);
    ans = min(ans, D[N - 1][1]);

    cout << ans << endl;

    return 0;
}
