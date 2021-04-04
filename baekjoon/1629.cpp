//
// Created by 신승민 on 2021/04/04.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

#define pb push_back
#define all(X) begin((X)), end((X))
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<ll> vll;

ll ans(ll a, ll b, ll c) {
    if (b == 0) return 1;
    if (b == 1) return a % c;

    if (b % 2 == 0) {
        ll factor = ans(a % c, b / 2, c);
        return (factor * factor) % c;
    } else return (a % c * ans(a % c, b - 1, c)) % c;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    cout << ans(a, b, c) << endl;

    return 0;
}