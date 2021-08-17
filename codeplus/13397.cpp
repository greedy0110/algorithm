//
// Created by 신승민 on 2021/08/17.
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

int N, M;
vi A;

bool go(int diff) {
    int cnt = 1;
    int t1 = A[0];
    int t2 = A[0];
    for (int i = 1; i < N; i++) {
        t1 = min(t1, A[i]);
        t2 = max(t2, A[i]);
        if (t2 - t1 > diff) {
            t1 = A[i];
            t2 = A[i];
            cnt++;
        }
    }
    return cnt <= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    A = vi(N);
    int left = 0, right = 0, ans, mid;
    RP(i, N) {
        cin >> A[i];
        right = max(right, A[i]);
    }

    while (left <= right) {
        mid = (left + right) / 2;
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
