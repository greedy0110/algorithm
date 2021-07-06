//
// Created by 신승민 on 2021/07/05.
//

#include <bits/stdc++.h>

using namespace std;

int N;
const int MOD = 10007;

int cache[10][1001] = {};

int find(int seed, int len) {
    int &cac = cache[seed][len];
    if (cac != 0) return cac;

    if (len == N) return 1;

    int ans = 0;
    for (int i = seed; i < 10; i++) {
        ans += find(i, len + 1);
    }
    return cac = ans % MOD;
}

int main() {
    scanf("%d", &N);
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += find(i, 1);
    }

    printf("%d\n", ans % MOD);

    return 0;
}
