//
// Created by 신승민 on 2021/08/04.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'
#define custom_pq(X) priority_queue<X, vector<X>, X>

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int N = 19;
    int A[N][N];
    RP(x, N) RP(y, N) cin >> A[x][y];

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            int cur = A[x][y];
            if (cur == 0) continue;

            bool ignore_right = false;
            ignore_right = ignore_right || (y + 5 < N && A[x][y + 5] == cur);
            ignore_right = ignore_right || (y - 1 >= 0 && A[x][y - 1] == cur);

            bool ignore_down = false;
            ignore_down = ignore_down || (x + 5 < N && A[x + 5][y] == cur);
            ignore_down = ignore_down || (x - 1 >= 0 && A[x - 1][y] == cur);

            bool ignore_cross = false;
            ignore_cross = ignore_cross || (x + 5 < N && y + 5 < N && A[x + 5][y + 5] == cur);
            ignore_cross = ignore_cross || (x - 1 >= 0 && y - 1 >= 0 && A[x - 1][y - 1] == cur);

            bool ignore_upcross = false;
            ignore_upcross = ignore_upcross || (x - 5 >= 0 && y + 5 < N && A[x - 5][y + 5] == cur);
            ignore_upcross = ignore_upcross || (x + 1 < N && y - 1 >= 0 && A[x + 1][y - 1] == cur);

            if (!ignore_right) {
                bool ok = true;
                for (int i = 1; i < 5; i++) {
                    if (y + i >= N) {
                        ok = false;
                        break;
                    }
                    if (cur != A[x][y + i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cout << cur << endl;
                    cout << x + 1 << " " << y + 1 << endl;
                    return 0;
                }
            }

            if (!ignore_down) {
                bool ok = true;
                for (int i = 1; i < 5; i++) {
                    if (x + i >= N) {
                        ok = false;
                        break;
                    }
                    if (cur != A[x + i][y]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cout << cur << endl;
                    cout << x + 1 << " " << y + 1 << endl;
                    return 0;
                }
            }

            if (!ignore_cross) {
                bool ok = true;
                for (int i = 1; i < 5; i++) {
                    if (x + i >= N || y + i >= N) {
                        ok = false;
                        break;
                    }
                    if (cur != A[x + i][y + i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cout << cur << endl;
                    cout << x + 1 << " " << y + 1 << endl;
                    return 0;
                }
            }

            if (!ignore_upcross) {
                bool ok = true;
                for (int i = 1; i < 5; i++) {
                    if (x - i < 0 || y + i >= N) {
                        ok = false;
                        break;
                    }
                    if (cur != A[x - i][y + i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cout << cur << endl;
                    cout << x + 1 << " " << y + 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << 0 << endl;
    return 0;
}
