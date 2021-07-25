//
// Created by 신승민 on 2021/07/25.
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

    int T;
    cin >> T;
    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        x--;
        y--;
        bool ok = false;
        for (int k = x; k < N * M; k += M) {
            if (k % N == y) {
                cout << k + 1 << endl;
                ok = true;
                break;
            }
        }
        if (!ok) cout << -1 << endl;
    }

    return 0;
}
