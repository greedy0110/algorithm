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

// 0 -> 평행
// 1 -> 반시계
// -1 -> 시계
int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    ll op = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);

    if (op == 0) return 0;
    else if (op > 0) return 1;
    else return -1;
}

void solve() {
    ll x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    if (x3 > x4) {
        swap(x3, x4);
        swap(y3, y4);
    }
    assert(x1 <= x2 && x3 <= x4);

    bool px1 = x1 == x2;
    bool px2 = x3 == x4;

    if (px1 && px2) {
        if (x1 != x3) {
            cout << 0 << endl;
            return;
        }

        if (y1 > y2) swap(y1, y2);
        if (y3 > y4) swap(y3, y4);

        bool mutual = y2 < y3 || y4 < y1;

        cout << (mutual ? 0 : 1) << endl;
        return;
    }

    bool py1 = y1 == y2;
    bool py2 = y3 == y4;

    if (py1 && py2) {
        if (y1 != y3) {
            cout << 0 << endl;
            return;
        }

        if (x1 > x2) swap(x1, x2);
        if (x3 > x4) swap(x3, x4);

        bool mutual = x2 < x3 || x4 < x1;

        cout << (mutual ? 0 : 1) << endl;
        return;
    }

    pair<ll, ll> p1 = make_pair(x1, y1);
    pair<ll, ll> p2 = make_pair(x2, y2);
    pair<ll, ll> p3 = make_pair(x3, y3);
    pair<ll, ll> p4 = make_pair(x4, y4);

    int ins_f1 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
    int ins_f2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);

    cout << ((ins_f1 <= 0 && ins_f2 <= 0) ? 1 : 0) << endl;
}
