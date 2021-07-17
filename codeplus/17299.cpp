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
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N), NGF(N, -1), F(1000001, 0);
    RP(i, N) {
        cin >> A[i];
        F[A[i]]++;
    }
    stack<int> ids; // 오등큰수를 못찾은 것, 내림 차순으로 쌓이게 된다.
    ids.push(0);

    for (int i = 1; i < N; i++) {
        while (!ids.empty() && F[A[i]] > F[A[ids.top()]]) {
            NGF[ids.top()] = A[i];
            ids.pop();
        }
        ids.push(i);
    }
    RP(i, N) cout << NGF[i] << " ";
    cout << endl;

    return 0;
}
