//
// Created by 신승민 on 2021/08/08.
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

    int N, M;
    cin >> N >> M;
    vi A(N), B(M), C(N + M);
    RP(i, N) cin >> A[i];
    RP(i, M) cin >> B[i];

    int ai = 0, bi = 0, k = 0;

    while (ai < N && bi < M) {
        if (A[ai] < B[bi]) C[k++] = A[ai++];
        else C[k++] = B[bi++];
    }

    while (ai < N) C[k++] = A[ai++];
    while (bi < M) C[k++] = B[bi++];

    RP(i, k) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}
