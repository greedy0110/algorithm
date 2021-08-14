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
    ll cnt = 0;
    auto cur = A.begin();
    while (cur != A.end()) {
        // 설치하고 다음 거로 넘겨.
        cnt++;
        cur = upper_bound(all(A), *cur + X - 1);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    ll C;
    cin >> N >> C;
    vector<ll> A(N);
    RP(i, N) cin >> A[i];
    sort(all(A));

    ll left = 1, right = A.back() - A.front();
    while (left != right) {
        ll mid = (left + right + 1) / 2;
        if (f(A, mid) >= C) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << left << endl;

    return 0;
}
