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
typedef vector<ll> vll;
typedef vector<vll> vvll;

vll A;
vvll dp;
int N;

ll go(int i, int j) {
    int last = max(i, j);
    if (last == N) return 0;

    ll &cac = dp[i][j];
    if (cac != -1) return cac;
    ll a = A[i], b = A[j];

    int cur_song = last + 1;
    cac = 4e18;

    ll cost = !i ? 0 : abs(A[cur_song] - a);
    cac = min(cac, cost + go(cur_song, j));

    cost = !j ? 0 : abs(A[cur_song] - b);
    cac = min(cac, cost + go(i, cur_song));

    return cac;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    A = vll(N+1);
    RP(i, N) cin >> A[i+1];
    dp = vvll(N + 1, vll(N + 1, -1));

    cout << go(0, 0) << endl;

    return 0;
}
