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

    while (true) {
        int K;
        cin >> K;
        if (K == 0) break;

        vector<int> numbers(K);
        RP(i, K) cin >> numbers[i];

        vector<int> P(K, 0);
        for (int i = 0; i < 6; i++) {
            P[i] = 1;
        }

        do {
            RP(i, K) {
                if (P[i] == 1) cout << numbers[i] << " ";
            }
            cout << endl;
        } while (prev_permutation(all(P)));
        cout << endl;
    }

    return 0;
}
