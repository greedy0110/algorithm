//
// Created by 신승민 on 2021/09/17.
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

typedef vector<ll> vll;

vll dp, sqr;

string ans;

void solve(int n, ll i) {
    if (n == 0) return;
    if (i == 0) {
        ans.push_back(')');
        solve(n - 1, i);
        return;
    }

    ll p = sqr[n - 1];
    if (i < p) {
        ans.push_back(')');
        solve(n - 1, i);
        return;
    } else {
        ans.push_back('(');
        solve(n - 1, i - p);
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    ll k;
    cin >> n >> k;
    dp = vll(n + 1, 0);
    sqr = vll(n + 1, 0);

    dp[0] = 1;
    for (int i = 2; i <= n; i += 2) {
        dp[i] = 1; // 전체가, 하나의 괄호 문자열 ((()))) 일 수 있음.
        for (int j = 2; j <= i - 2; j += 2) {
            dp[i] += dp[j] * dp[i - j];
            if (j != 2) dp[i] -= dp[j - 2]; // 중복 제거.
        }
        cout << i << " " << dp[i] << endl;
    }

    sqr[0] = 1;
    for (int i = 1; i <= n; i++) {
        sqr[i] = 2 * sqr[i - 1];
    }

    for (int i = 0; i <= n; i++) {
        cout << i << " " << sqr[i] - dp[i] << endl;
    }

    ll reverse_order = sqr[n] - dp[n] - k - 1;

    if (reverse_order < 0) {
        cout << -1 << endl;
        return 0;
    }

    solve(n, reverse_order);
    cout << ans << endl;

    return 0;
}
