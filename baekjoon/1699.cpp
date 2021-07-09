//
// Created by 신승민 on 2021/07/09.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int ls = -1;
    int dp[100005] = {0};
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        int sq = sqrt(i);
        if (sq * sq == i) {
            ls = sq;
            dp[i] = 1;
            continue;
        }

        dp[i] = INT_MAX;
        for (int j = 1; j <= ls; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + dp[j * j]);
        }
    }

    printf("%d\n", dp[N]);

    return 0;
}
