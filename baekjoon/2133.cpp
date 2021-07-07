//
// Created by 신승민 on 2021/07/07.
//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int N;
    ll dp[31] = {};
    dp[0] = 1;
    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        dp[i] += dp[i - 2];
        for (int j = i - 2; j >= 0; j -= 2) {
            dp[i] += 2 * dp[j];
        }
    }
    printf("%lld\n", dp[N]);

    return 0;
}
