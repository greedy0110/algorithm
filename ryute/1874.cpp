//
// Created by 신승민 on 2021/07/15.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, idx;
    scanf("%d", &N);
    vector<int> A(N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    vector<char> ans;
    stack<int> S;

    idx = 0;
    for (int inc = 1; inc <= N; inc++) {
        S.push(inc);
        ans.push_back('+');

        while (!S.empty() && S.top() == A[idx]) {
            S.pop();
            ans.push_back('-');
            idx++;
        }
    }

    if (S.empty()) {
        for (char c : ans) {
            printf("%c\n", c);
        }
    } else {
        printf("NO\n");
    }

    return 0;
}
