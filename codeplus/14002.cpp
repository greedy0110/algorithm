//
// Created by 신승민 on 2021/07/19.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

void go(const vector<int> &A, const vector<int> &V, int p) {
    if (p == -1) return;

    go(A, V, V[p]);
    cout << A[p] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // D[i]: A[i] 로 끝나는 LIS 의 최대 길이
    // V[i]: A[i] 로 끝나는 LIS 상 앞에 오는 A[j] 의 j index.
    int N;
    cin >> N;
    vector<int> A(N), D(N, 1), V(N, -1);
    RP(i, N) cin >> A[i];

    D[0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && D[j] + 1 > D[i]) {
                D[i] = D[j] + 1;
                V[i] = j;
            }
        }
    }

    int mi = distance(D.begin(), max_element(all(D)));
    cout << D[mi] << endl;
    go(A, V, mi);
    cout << endl;

    return 0;
}
