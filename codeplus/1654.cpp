//
// Created by 신승민 on 2021/08/14.
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

ll f(const vector<ll> &A, ll X) {
    ll ret = 0;
    for (ll a : A) {
        ret += a / X;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K, N;
    cin >> K >> N;
    vector<ll> A(K);
    RP(i, K) cin >> A[i];

    ll left = 1, right = *max_element(all(A));
    while (left != right) {
        ll mid = (left + right + 1) / 2;
        if (f(A, mid) >= N) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;

    return 0;
}
