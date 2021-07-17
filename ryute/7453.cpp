//
// Created by 신승민 on 2021/07/17.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    scanf("%d", &N);
//    N = 4000;
    vector<int> A(N), B(N), C(N), D(N), AB(N * N), CD(N * N);
    RP(i, N) {
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
//        A[i] = B[i] = C[i] = D[i] = 0;
    }

    int abi = 0;
    RP(a, N) RP(b, N) AB[abi++] = A[a] + B[b];
    int cdi = 0;
    RP(a, N) RP(b, N) CD[cdi++] = C[a] + D[b];

    sort(all(AB));
    sort(all(CD));

    long long ans = 0;

    RP(ab, N * N) {
        int cnt = upper_bound(all(CD), -AB[ab]) - lower_bound(all(CD), -AB[ab]);
        ans += cnt;
    }
    printf("%lld\n", ans);

    return 0;
}
