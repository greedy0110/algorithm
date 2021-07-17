//
// Created by 신승민 on 2021/07/17.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> deck;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    scanf("%d", &N);
    deck A(N);
    RP(i, N) scanf("%d", &A[i]);
    scanf("%d", &M);
    deck B(M);
    RP(i, M) scanf("%d", &B[i]);

    sort(all(A));
    RP(i, M) {
        int cnt = upper_bound(all(A), B[i]) - lower_bound(all(A), B[i]);
        printf("%d ", cnt);
    }
    printf("\n");

    return 0;
}
