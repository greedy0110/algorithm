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
    cin.tie(NULL);

    int N, M, ci = 0;
    scanf("%d %d", &N, &M);

    vector<int> A(N), B(M), C(N);
    RP(i, N) scanf("%d", &A[i]);
    RP(i, M) scanf("%d", &B[i]);

    sort(all(A));
    sort(all(B));

    RP(i, N) {
        if (!binary_search(all(B), A[i])) {
            C[ci++] = A[i];
        }
    }

    printf("%d\n", ci);
    RP(i, ci) printf("%d ", C[i]);
    printf("\n");

    return 0;
}
