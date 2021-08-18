//
// Created by 신승민 on 2021/08/18.
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

ll N, K;

bool go(ll A) {
    // A 보다 작은 갯수 반환.
    // A가 K 번째 수 보다 뒤에있냐.
    ll cnt = 0;
    for (ll i = 1; i <= N; i++) {
        cnt += min(N, A/i);
    }
    return cnt >= K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    ll left = 1, right = N * N, ans, mid;

    while (left <= right) {
        mid = (left + right) / 2;
        // mid 커 클 때 true. 이 조건을 만족하는 가장 큰 Mid를 찾아야 하므로...
        if (go(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}
