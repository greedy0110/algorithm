//
// Created by 신승민 on 2021/07/10.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> arr, dp;
int N, K;
const int MAX = 9999999;

int main() {
    scanf("%d %d", &N, &K);
    arr = vector<int>(N);
    dp = vector<int>(K + 1, MAX);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    dp[0] = 0;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[j] <= i) {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }

    printf("%d\n", dp[K] == MAX ? -1 : dp[K]);
    return 0;
}
