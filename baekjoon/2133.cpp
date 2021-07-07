//
// Created by 신승민 on 2021/07/07.
//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cac2[31] = {};
ll cac3[31][2][2][2] = {};

ll fill2(int len) {
    ll &cac = cac2[len];
    if (cac != 0) return cac;

    if (len == 0) return 1;
    else if (len < 0) return 0;
    return cac = fill2(len - 2) + fill2(len - 1);
}

ll fill3(int len, int c1, int c2, int c3) {
    ll &cac = cac3[len][c1][c2][c3];
    if (cac != 0) return cac;

    if (len == 0) return 1;
    else if (len < 0) return 0;

    ll ans = 0;
    if (c3 == 1) {
        for (int i = 1; i <= len - 1; i += 2) {
            ans += fill2(i) * fill3(len - i - 1, 0, 1, 0);
        }
    }
    if (c2 == 1) {
        for (int i = 1; i <= len - 1; i += 2) {
            ans += fill2(i) * fill3(len - i - 1, 0, 0, 1);
        }
    }
    if (c1 == 1) {
        ans += fill3(len - 2, 1, 1, 1);
    }

    return cac = ans;
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%lld\n", fill3(N, 1, 1, 1));
    return 0;
}
