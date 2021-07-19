//
// Created by 신승민 on 2021/07/19.
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

    const int MOD = 1000000009;
    const int MAX = 1000000;
    long long D[MAX + 1];
    D[0] = 0;
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;
    for (int i = 4; i <= MAX; i++) {
        D[i] = D[i - 3] + D[i - 2] + D[i - 1];
        D[i] %= MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cout << D[N] << endl;
    }

    return 0;
}
