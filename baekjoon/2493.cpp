//
// Created by 신승민 on 2021/08/06.
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

    stack<int> S;
    int N;
    cin >> N;
    vi A(N), B(N, -1);
    RP(i, N) cin >> A[i];

    for (int i = N - 1; i >= 0; i--) {
        while (!S.empty() && A[S.top()] <= A[i]) {
            B[S.top()] = i;
            S.pop();
        }
        assert(S.empty() || A[S.top()] > A[i]);
        S.push(i);
    }

    RP(i, N) {
        cout << B[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}
