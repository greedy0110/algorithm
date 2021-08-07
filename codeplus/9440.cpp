//
// Created by 신승민 on 2021/08/07.
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

ll min_number(vi &A) {
    if (A.empty()) return -1;
    sort(all(A));
    if (A.back() == 0) return -1;
    int dist = lower_bound(all(A), 1) - A.begin();
    swap(A[0], A[dist]);
    int cur = 0;
    for (int a : A) {
        cur = cur * 10 + a;
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;
        vi A(N);
        RP(i, N) cin >> A[i];

        // 브루트 포스로 쓰기엔 N이 너무 크다. O(N * N!) 이기 때문...

        sort(all(A));
        if (A[0] == 0) {
            int dist = lower_bound(all(A), 1) - A.begin();
            swap(A[0], A[dist]);

            if (A[1] == 0) {
                swap(A[1], A[dist + 1]);
            }
        }

        if (N % 2 == 1) {
            A.insert(A.begin(), 0);
        }

        int cur = 0;
        for (int i = 0; i < N; i += 2) {
            cur = cur * 10 + A[i] + A[i + 1];
        }
        cout << cur << endl;
    }

    return 0;
}
