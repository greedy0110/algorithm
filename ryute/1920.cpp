//
// Created by 신승민 on 2021/07/12.
//

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    int N, M, temp;
    scanf("%d", &N);
    vi a(N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &temp);
        printf("%d\n", binary_search(a.begin(), a.end(), temp) ? 1 : 0);
    }

    return 0;
}