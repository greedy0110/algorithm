//
// Created by 신승민 on 2021/09/15.
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

vector<vector<ll>> bins;

ll binary(int n, int m) {
    ll &cac = bins[n][m];
    if (cac != -1) return cac;
    if (n == 0 || m == 0) return cac = 1;

    ll ans = binary(n - 1, m);
    if (m > 0) ans += binary(n - 1, m - 1);

    return cac = ans;
}

string ans;

void solve(int n, int m, ll i) {
    if (n == 0) return;
    if (m == 0) {
        ans.push_back('0');
        solve(n - 1, m, i);
        return;
    }

    int bin = binary(n - 1, m);
    if (i >= bin) {
        ans.push_back('1');
        solve(n - 1, m - 1, i - bin);
    } else {
        ans.push_back('0');
        solve(n - 1, m, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, l;
    ll i;
    cin >> n >> l >> i;
    bins = vector<vector<ll>>(n + 1, vector<ll>(n + 1, -1));

    solve(n, l, i - 1);
    cout << ans << endl;

    return 0;
}
