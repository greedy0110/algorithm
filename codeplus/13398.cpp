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

    int A[100001], D[100001], R[100001];
    int N;
    cin >> N;
    RP(i, N) cin >> A[i];

    D[0] = A[0];
    for (int i = 1; i < N; i++) {
        D[i] = max(A[i], D[i - 1] + A[i]);
    }

    R[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        R[i] = max(A[i], R[i + 1] + A[i]);
    }

    int ans = D[0];
    for (int i = 1; i < N; i++) {
        ans = max(ans, D[i]);
    }

    for (int i = 1; i < N - 1; i++) {
        ans = max(ans, D[i - 1] + R[i + 1]);
    }

    cout << ans << endl;

    return 0;
}
