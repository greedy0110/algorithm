//
// Created by 신승민 on 2021/07/10.
//

#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int v[101];
    int d[10001] = {};
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    d[0] = 1;

    for (int i = 0; i < n; i++) { // coin 반복
        for (int j = 1; j <= k; j++) { // k 원까지 반복
            if (j >= v[i]) { // 이번에 비교하는 코인보다 클 때는...
                d[j] += d[j - v[i]]; // 코인 하나 사용, 이미 앞에 다 반영되어 있음.
            }
        }
    }

    printf("%d\n", d[k]);
    return 0;
}
