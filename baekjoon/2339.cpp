//
// Created by 신승민 on 2021/08/13.
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

vvi A;
int N;

ll go(int x1, int y1, int x2, int y2, int dir) {
    bool ok = true;
    int cnt = 0;
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            if (A[x][y] == 1) {
                ok = false;
                break;
            } else if (A[x][y] == 2) {
                cnt++;
                if (cnt >= 2) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) break;
    }

    if (ok && cnt == 1) {
        return 1;
    }

    ll ans = 0;
    if (dir != 0) {
        for (int x = x1; x <= x2; x++) {
            bool check = false;
            for (int y = y1; y <= y2; y++) {
                if (A[x][y] == 1) {
                    check = true;
                } else if (A[x][y] == 2) {
                    check = false;
                    break;
                }
            }

            if (check) { // x 기준으로 자른다.
                ll a1 = go(x1, y1, x - 1, y2, 0);
                ll a2 = go(x + 1, y1, x2, y2, 0);
                if (a1 != 0 && a2 != 0) {
                    ans += a1 * a2;
                }
            }
        }
    }
    if (dir != 1) {
        for (int y = y1; y <= y2; y++) {
            bool check = false;
            for (int x = x1; x <= x2; x++) {
                if (A[x][y] == 1) {
                    check = true;
                } else if (A[x][y] == 2) {
                    check = false;
                    break;
                }
            }

            if (check) { // y 기준으로 자른다.
                ll a1 = go(x1, y1, x2, y - 1, 1);
                ll a2 = go(x1, y + 1, x2, y2, 1);
                if (a1 != 0 && a2 != 0) {
                    ans += a1 * a2;
                }
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    A = vvi(N, vi(N));
    RP(x, N) RP(y, N) cin >> A[x][y];

    ll ans = go(0, 0, N - 1, N - 1, -1);
    if (ans == 0) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
