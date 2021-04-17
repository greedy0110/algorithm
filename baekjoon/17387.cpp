//
// Created by 신승민 on 2021/04/17.
//

#include <bits/stdc++.h>

using namespace std;

#define all(X) begin((X)), end((X))
#define endl '\n'
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define repeat(i, X) for (int i=0; i<((X)); i++)
#define BIG 100000007
#define SUPER_BIG 987654321123456789

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<string> vs;
typedef priority_queue<int, vi, greater<>> mq;
typedef priority_queue<pii, vpii, greater<>> mpq;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

void solve() {
    ll x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    if (x1 > x2) {
        ll temp = x1;
        x1 = x2;
        x2 = temp;
        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    if (x3 > x4) {
        ll temp = x3;
        x3 = x4;
        x4 = temp;
        temp = y3;
        y3 = y4;
        y4 = temp;
    }
    assert(x1 <= x2 && x3 <= x4);

    bool px1 = x1 == x2;
    bool px2 = x3 == x4;

    if (px1) {
        cout << ((x3 <= x1 && x1 <= x4) ? 1 : 0) << endl;
        return;
    }

    if (px2) {
        cout << ((x1 <= x3 && x3 <= x2) ? 1 : 0) << endl;
        return;
    }
    assert(x1 != x2 && x3 != x4);

    ll xs = x1 - x2;
    ll xf = x3 - x4;

    if ((y1 - y2) * (x3 - x4) == (y3 - y4) * (x1 - x2)) {
        bool not_interact = x2 < x3 || x4 < x1;
        bool same_y_inter = xs * xf * y1 - x1 * xf * (y1 - y2) == xs * xf * y3 - x3 * xs * (y3 - y4);

        cout << ((same_y_inter && !not_interact) ? 1 : 0) << endl;
        return;
    }

    ll X = xf * (y1 - y2) - xs * (y3 - y4);
    ll Xa = xs * xf * (y3 - y1) - xs * (y3 - y4) * x3 + xf * (y1 - y2) * x1;

    bool intersect = X * x1 <= Xa && Xa <= X * x2 && X * x3 <= Xa && Xa <= X * x4;
    if (X < 0) {
        intersect = X * x1 >= Xa && Xa >= X * x2 && X * x3 >= Xa && Xa >= X * x4;
    }

    cout << (intersect ? 1 : 0) << endl;
}
