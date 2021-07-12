//
// Created by 신승민 on 2021/07/12.
//

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    int N, M, temp;
    vi A;

    scanf("%d", &N);
    A = vi(N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    sort(A.begin(), A.end());

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &temp);
        printf("%d ", binary_search(A.begin(), A.end(), temp) ? 1 : 0);
    }
    printf("\n");

    return 0;
}
