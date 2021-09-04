//
// Created by 신승민 on 2021/07/10.
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
    int n, k;
    const int MOD = 10007;
    cin >> n >> k;

    int dp[1001][1001] = {};

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}