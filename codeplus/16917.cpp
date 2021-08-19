//
// Created by 신승민 on 2021/08/19.
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

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int mc = max(X, Y) * 2;
    int ans = 1e9;
    for (int c = 0; c <= mc; c += 2) {
        int a = max(0, X - c / 2), b = max(0, Y - c / 2);
        ans = min(ans, c * C + a * A + b * B);
    }
    cout << ans << endl;

    return 0;
}
