//
// Created by 신승민 on 2021/07/10.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    const int MOD = 10007;
    scanf("%d %d", &n, &k);

    int dp[1001][1001] = {};

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    printf("%d\n", dp[n][k]);
    return 0;
}