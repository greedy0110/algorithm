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

    int D[1001] = {}, D2[1001] = {}, A[1001];
    int N;
    cin >> N;
    RP(i, N) cin >> A[i];

    D[0] = 1;
    for (int i = 1; i < N; i++) {
        D[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                D[i] = max(D[i], D[j] + 1);
            }
        }
    }

    D2[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--) {
        D2[i] = 1;
        for (int j = i + 1; j <= N - 1; j++) {
            if (A[i] > A[j]) {
                D2[i] = max(D2[i], D2[j] + 1);
            }
        }
    }

    int ans = D[0] + D2[0] - 1;
    for (int i = 1; i < N; i++) {
        ans = max(ans, D[i] + D2[i] - 1);
    }
    cout << ans << endl;

    return 0;
}
