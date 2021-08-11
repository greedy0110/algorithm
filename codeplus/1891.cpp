//
// Created by 신승민 on 2021/08/10.
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

string str;
bool ok = true;

string gogo(ll cx, ll cy, ll x, ll y, ll s) {
    if (s == 1) return "";
    ll ns = s / 2;
    string ans;
    ll nx = cx, ny = cy;

    bool top = cx <= x && x < cx + ns;
    bool bottom = cx + ns <= x && x < cx + s;
    bool left = cy <= y && y < cy + ns;
    bool right = cy + ns <= y && y < cy + s;

    if (top && left) {
        ans = "2";
    } else if (top && right) {
        ny += ns;
        ans = "1";
    } else if (bottom && left) {
        nx += ns;
        ans = "3";
    } else if (bottom && right) {
        nx += ns;
        ny += ns;
        ans = "4";
    } else {
        ok = false;
    }
    return ans + gogo(nx, ny, x, y, ns);
}

pair<ll, ll> go(int index, ll x, ll y, ll s) {
    if (s == 1) {
        return {x, y};
    }

    ll ns = s / 2, nx = x, ny = y;
    switch (str[index]) {
        case '2':
            break;
        case '1':
            ny += ns;
            break;
        case '3':
            nx += ns;
            break;
        case '4':
            nx += ns;
            ny += ns;
            break;
    }

    return go(index + 1, nx, ny, ns);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int d;
    cin >> d >> str;
    ll dx, dy;
    const ll one = 1;
    cin >> dy >> dx;
    dx = -dx;

    auto ret = go(0, 0, 0, (one << d));
    ret.first += dx;
    ret.second += dy;

    string ans = gogo(0, 0, ret.first, ret.second, (one << d));
    if (ok) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}
