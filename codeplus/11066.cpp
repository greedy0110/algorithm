//
// Created by 신승민 on 2021/09/01.
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

vi A, P;
vvi cache;

int go(int i, int j) {
    if (i == j) return 0;
    int &cac = cache[i][j];
    if (cac != -1) return cac;

    int ans = 1e9;
    for (int k = i; k < j; k++) {
        ans = min(ans, go(i, k) + go(k + 1, j) + P[k + 1] - P[i] + P[j + 1] - P[k + 1]);
    }
    return cac = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        A = vi(N);
        cache = vvi(N, vi(N, -1));
        RP(i, N) cin >> A[i];
        P = vi(N + 1);
        P[0] = 0;
        RP(i, N) {
            P[i + 1] = P[i] + A[i];
        }
        cout << go(0, N - 1) << endl;
    }

    return 0;
}
