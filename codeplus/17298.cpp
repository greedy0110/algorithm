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
    vector<int> A(N), NGE(N, -1);
    RP(i, N) cin >> A[i];
    stack<int> ids; // 아직 오큰 수를 찾지 못한 것의 index

    ids.push(0);
    for (int i = 1; i < N; i++) {
        if (!ids.empty()) {
            int tid = ids.top();
            while (A[i] > A[tid]) {
                NGE[tid] = A[i];
                ids.pop();
                if (ids.empty()) break;
                tid = ids.top();
            }
        }
        ids.push(i);
    }

    for (int v : NGE) cout << v << " ";
    cout << endl;

    return 0;
}
