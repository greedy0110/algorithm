//
// Created by 신승민 on 2021/07/27.
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
    vector<int> A(N);
    RP(i, N) cin >> A[i];
    if (prev_permutation(all(A))) {
        RP(i, N) cout << A[i] << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
