//
// Created by 신승민 on 2021/08/29.
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

vi find_fail(string p) {
    int m = p.size();
    vi fail(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = fail[j - 1];
        if (p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        string s;
        cin >> s;
        if (s == ".") break;

        vi fail = find_fail(s);
        ll lt = fail.back();
        int N = s.size();

        ll ans = 1;
        for (ll p = N; p >= 2; p--) {
            if ((p - 1) * N % p == 0 && lt == (p - 1) * N / p) {
                ans = p;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
