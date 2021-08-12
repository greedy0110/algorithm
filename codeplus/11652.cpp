//
// Created by 신승민 on 2021/08/12.
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> A(N);
    RP(i, N) cin >> A[i];

    sort(all(A));
    int ans_cnt = 1, cnt = 1;
    ll ans = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i - 1] == A[i]) {
            cnt++;
        } else {
            cnt = 1;
        }

        if (ans_cnt < cnt) {
            ans_cnt = cnt;
            ans = A[i];
        }
    }
    cout << ans << endl;

    return 0;
}
