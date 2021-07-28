//
// Created by 신승민 on 2021/07/29.
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
    int S[21][21];
    RP(i, N) RP(j, N) cin >> S[i][j];

    int ans = 100 * 20 + 1;
    for (int i = 0; i < (1 << N); i++) {
        vector<int> t1, t2;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) t1.push_back(j);
            else t2.push_back(j);
        }
        if (t1.size() != N / 2) continue;

        int s1 = 0, s2 = 0;
        for (int m1 = 0; m1 < N / 2; m1++) {
            for (int m2 = 0; m2 < N / 2; m2++) {
                s1 += S[t1[m1]][t1[m2]];
                s2 += S[t2[m1]][t2[m2]];
            }
        }

        ans = min(ans, abs(s1 - s2));
    }

    cout << ans << endl;

    return 0;
}
