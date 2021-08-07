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

    int N, M;
    cin >> N >> M;

    int ans;
    if (N == 1) {
        ans = 1;
    } else if (N == 2) {
        ans = min((M + 1) / 2, 4);
    } else {
        if (M >= 7) ans = M - 2;
        else ans = min(M, 4);
    }
    cout << ans << endl;

    return 0;
}
