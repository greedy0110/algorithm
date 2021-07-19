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

    int N;
    cin >> N;
    vector<int> P(N + 1);
    P[0] = 0;
    RP(i, N) cin >> P[i + 1];
    vector<int> D(N + 1, -1);
    D[0] = 0;
    D[1] = P[1];

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (D[i] == -1) D[i] = D[i - j] + P[j];
            else D[i] = min(D[i], D[i - j] + P[j]);
        }
    }

    cout << D[N] << endl;

    return 0;
}
