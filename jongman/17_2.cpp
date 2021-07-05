//
// Created by 신승민 on 2021/07/05.
//

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int waysToBuy(const vi &psum, int k) {
    vector<long long> f(k, 0);
    for (int i = 0; i < psum.size(); i++) f[psum[i]] += 1;

    long long ans = 0;
    for (int i = 0; i < k; i++) {
        if (f[i] >= 2) {
            ans += f[i] * (f[i] - 1) / 2;
            ans %= 20091101;
        }
    }

    return (int) ans;
}

int maxBuys(const vi &psum, int k) {
    vi result(psum.size(), 0);
    vi previous(k, -1);

    for (int i = 0; i < psum.size(); i++) {
        if (i > 0) result[i] = result[i - 1];
        else result[i] = 0;

        int loc = previous[psum[i]];
        if (loc != -1) result[i] = max(result[i], result[loc] + 1);

        previous[psum[i]] = i;
    }

    return result.back();
}

vi solve(int N, int K, const vi &D) {
    vi psum;

    psum = vi(N + 1);
    psum[0] = 0;
    for (int i = 1; i < psum.size(); i++) {
        psum[i] = psum[i - 1] + D[i - 1];
        psum[i] %= K;
    }

    return vi{waysToBuy(psum, K), maxBuys(psum, K)};
}

int main() {
    int C, N, K;
    vi D;

    scanf("%d", &C);
    while (C--) {
        scanf("%d %d", &N, &K);

        D = vi(N);
        for (int i = 0; i < N; i++) scanf("%d", &D[i]);
        vi ans = solve(N, K, D);

        printf("%d %d\n", ans[0], ans[1]);
    }

    return 0;
}