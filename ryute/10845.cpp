//
// Created by 신승민 on 2021/07/12.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, temp;
    string cmd;
    queue<int> q;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cmd;
        if (cmd == "push") {
            scanf("%d", &temp);
            q.push(temp);
        } else if (cmd == "pop") {
            if (q.empty()) {
                printf("-1\n");
                continue;
            }
            printf("%d\n", q.front());
            q.pop();
        } else if (cmd == "size") {
            printf("%d\n", q.size());
        } else if (cmd == "empty") {
            printf("%d\n", q.empty() ? 1 : 0);
        } else if (cmd == "front") {
            if (q.empty()) {
                printf("-1\n");
                continue;
            }
            printf("%d\n", q.front());
        } else {
            if (q.empty()) {
                printf("-1\n");
                continue;
            }
            printf("%d\n", q.back());
        }
    }
}