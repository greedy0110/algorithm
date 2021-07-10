//
// Created by 신승민 on 2021/07/10.
//

#include <bits/stdc++.h>

using namespace std;

bool desc_compare(int a, int b) {
    return a > b;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> dp, arr(N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    dp.push_back(INT_MAX);
    for (int i = 0; i < N; i++) {
        if (arr[i] < dp.back()) {
            dp.push_back(arr[i]);
        } else {
            *lower_bound(dp.begin(), dp.end(), arr[i], desc_compare) = arr[i];
        }
    }

    printf("%d\n", dp.size() - 1);
}
