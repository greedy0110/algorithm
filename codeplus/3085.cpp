//
// Created by 신승민 on 2021/07/23.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int N;

int check(const vector<string> &B) {
    // horizontal
    int ans = 1;
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        for (int j = 1; j < N; j++) {
            if (B[i][j - 1] == B[i][j]) cnt++;
            else cnt = 1;
            ans = max(ans, cnt);
        }
    }

    // vertical
    for (int j = 0; j < N; j++) {
        int cnt = 1;
        for (int i = 1; i < N; i++) {
            if (B[i - 1][j] == B[i][j]) cnt++;
            else cnt = 1;
            ans = max(ans, cnt);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<string> B(N);
    RP(i, N) cin >> B[i];

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // right
            if (j + 1 < N) {
                swap(B[i][j], B[i][j + 1]);
                ans = max(ans, check(B));
                swap(B[i][j], B[i][j + 1]);
            }

            // down
            if (i + 1 < N) {
                swap(B[i][j], B[i + 1][j]);
                ans = max(ans, check(B));
                swap(B[i][j], B[i + 1][j]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
