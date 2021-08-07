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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> D(N - 1), C(N);
    RP(i, N - 1) cin >> D[i];
    RP(i, N) cin >> C[i];

    ll cost = 1000000000;
    ll sum = 0;
    for (int i = 0; i < N - 1; i++) {
        cost = min(cost, C[i]);
        sum += cost * D[i];
    }
    cout << sum << endl;

    return 0;
}
