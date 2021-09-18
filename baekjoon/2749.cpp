//
// Created by 신승민 on 2021/09/18.
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

const ll MOD = 1000000007;

typedef vector<vector<ll>> matrix;

matrix mat_mult(matrix &a, matrix &b) {
    int n = a.size();
    int m = a[0].size();
    int l = b[0].size();
    matrix ret(n, vector<ll>(l, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < m; k++) {
                ret[i][j] += (a[i][k] * b[k][j]);
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

matrix mat_sqrt(matrix &a, ll n) {
    if (n == 1) return a;

    if (n % 2 == 0) {
        auto sub = mat_sqrt(a, n / 2);
        return mat_mult(sub, sub);
    } else {
        auto sub = mat_sqrt(a, n - 1);
        return mat_mult(sub, a);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    matrix a = {{1, 1},
                {1, 0}};
    auto ret = mat_sqrt(a, n);
    cout << ret[0][1] << endl;
    return 0;
}
