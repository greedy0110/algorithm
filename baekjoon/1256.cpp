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
typedef vector<vector<ll>> vvll;

vvll cache;
int n, m, k;

ll go(int a, int z) {
    if (a == 0 || z == 0) return 1;
    ll &ret = cache[a][z];
    if (ret != -1) return ret;
    ret = go(a - 1, z) + go(a, z - 1);
    if (ret >= k) return k;
    return ret;
}

string ans;

void solve(int a, int z, ll i) {
    if (a == 0 && z == 0) return;
    if (a == 0) {
        ans.push_back('z');
        solve(a, z - 1, i);
        return;
    }
    if (z == 0) {
        ans.push_back('a');
        solve(a - 1, z, i);
        return;
    }

    ll p = go(a - 1, z);
    if (i < p) {
        ans.push_back('a');
        solve(a - 1, z, i);
    } else {
        ans.push_back('z');
        solve(a, z - 1, i - p);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    cache = vvll(n + 1, vll(m + 1, -1));

    if (go(n, m) < k) {
        cout << -1 << endl;
        return 0;
    }

    solve(n, m, k - 1);
    cout << ans << endl;

    return 0;
}
