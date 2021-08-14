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

ll calc(ll N) {
    ll start_factor = 1, end_factor = 10, len_factor = 1, len = 0;
    while (end_factor / 10 <= N) {
        ll start = start_factor;
        ll end = end_factor - 1;
        if (end >= N) end = N;
        len += (end - start + 1) * len_factor;
        start_factor *= 10;
        end_factor *= 10;
        len_factor += 1;
    }
    return len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, k;
    cin >> N >> k;

    if (calc(N) < k) {
        cout << -1 << endl;
        return 0;
    }
    ll start = 1, end = N, mid;
    while (start != end) {
        mid = (start + end) / 2;
        if (calc(mid) >= k) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    ll diff = calc(start) - k;
    if (diff == 0) cout << start % 10 << endl;
    else {
        RP(_, diff) start /= 10;
        cout << start % 10 << endl;
    }

    return 0;
}
