//
// Created by 신승민 on 2021/09/04.
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

vvi cache;

bool go(vi &A, int s, int e) {
    if (s == e) return true;
    if (e - s == 1) return A[s] == A[e];

    int &cac = cache[s][e];
    if (cac != -1) return cac == 1;
    return cac = (A[s] == A[e] && go(A, s + 1, e - 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cache = vvi(N + 1, vi(N + 1, -1));
    vi A(N + 1);
    RP(i, N) cin >> A[i + 1];
    int M;
    cin >> M;
    RP(_, M) {
        int s, e;
        cin >> s >> e;
        cout << go(A, s, e) << endl;
    }

    return 0;
}
