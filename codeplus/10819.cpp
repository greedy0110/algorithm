//
// Created by 신승민 on 2021/07/27.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int calc(const vector<int> &d) {
    int sum = 0;
    for (int i = 0; i < d.size() - 1; i++) {
        sum += abs(d[i] - d[i + 1]);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    RP(i, N) cin >> A[i];
    sort(all(A));
    int ans = -1;
    do {
        ans = max(ans, calc(A));
    } while (next_permutation(all(A)));

    cout << ans << endl;

    return 0;
}
