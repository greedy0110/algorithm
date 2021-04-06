//
// Created by 신승민 on 2021/04/06.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <queue>
#include <numeric>
#include <set>
#include <map>

using namespace std;

#define all(X) begin((X)), end((X))
#define sz(X) (int)(X).size()
#define fi first
#define endl '\n'
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define BIG 987654321

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vll> vvll;
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

map<ll, ll> d;
int X = 1000000007;

ll f(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    else if (d.count(n) > 0) return d[n];

    if ((n & 1) == 0) {
        ll f1 = f(n / 2 - 1);
        ll f2 = f(n / 2);
        d[n] = (2 * f1 + f2) * f2;
        d[n] %= X;
        return d[n];
    } else {
        ll f1 = f((n + 1) / 2);
        ll f2 = f((n + 1) / 2 - 1);
        d[n] = f1 * f1 + f2 * f2;
        d[n] %= X;
        return d[n];
    }
}

void solve() {
    ll N;
    cin >> N;
    cout << f(N) << endl;
}
