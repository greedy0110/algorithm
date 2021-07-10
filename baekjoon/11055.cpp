//
// Created by 신승민 on 2021/07/10.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> s, dp(N), arr(N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    int ans = INT_MIN;
    for (int i = 0; i < N; i++) {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);

    return 0;
}
