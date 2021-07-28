//
// Created by 신승민 on 2021/07/29.
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

    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    RP(i, N) cin >> A[i];

    int ans = 0;
    for (int i = 1; i < (1 << N); i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) sum += A[j];
        }
        if (sum == S) ans++;
    }
    cout << ans << endl;

    return 0;
}
