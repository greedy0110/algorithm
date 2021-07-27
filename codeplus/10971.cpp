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

    int W[11][11];
    int N;
    cin >> N;
    RP(i, N) RP(j, N) cin >> W[i][j];
    vector<int> order(N);
    RP(i, N) order[i] = i;

    int ans = 1000000 * 10 + 1;
    do {
        bool ok = true;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int from = order[i];

            int next = i+1;
            if (next == N) next = 0;
            int to = order[next];

            if (W[from][to] == 0) {
                ok = false;
                break;
            }
            sum += W[from][to];
        }
        if (!ok) continue;
        ans = min(ans, sum);
    } while (next_permutation(all(order)));

    cout << ans << endl;

    return 0;
}
