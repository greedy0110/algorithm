//
// Created by 신승민 on 2021/09/01.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'
#define custom_pq(X) priority_queue<X, vector<X>, X>

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vi A(N), P(N); // P[i] -> A[i] 까지의 합.
        RP(i, N) {
            cin >> A[i];
            if (i == 0)P[i] = A[i];
            else P[i] = P[i - 1] + A[i];
        }
        vi dp(N);
        dp[0] = A[0];
        dp[1] = A[0] + A[1];
        for (int i = 2; i < N; i++) {
            dp[i] = min(dp[i - 1] + P[i - 1] + A[i], dp[i - 2] + P[i - 2] + 2 * (A[i - 1] + A[i]));
        }
        cout << dp[N - 1] << endl;
    }

    return 0;
}
