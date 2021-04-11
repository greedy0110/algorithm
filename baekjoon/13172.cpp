//
// Created by 신승민 on 2021/04/11.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <queue>
#include <numeric>
#include <set>
#include <map>

using namespace std;

#define all(X) begin((X)), end((X))
#define endl '\n'
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define repeat(i, X) for (int i=0; i<((X)); i++)
#define BIG 1000000007
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

int gcd(int a, int b) {
    if (b > a) {
        int temp = a;
        a = b;
        b = temp;
    }

    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

const int X = 1000000007;

ll modular(int a, int n) {
    if (n == 0) return 0;
    if (n == 1) return a;

    if (n % 2 == 0) {
        ll half_modular = modular(a, n / 2);
        return (half_modular * half_modular) % X;
    } else {
        return (a * modular(a, n - 1)) % X;
    }
}

class ModularSection {
public:
    ModularSection(int n, int s) {
        int d = gcd(n, s);

        _n = n / d;
        _s = s / d;

        mod = (_s * modular(_n, X - 2)) % X;
    }

    ll mod;

private:
    ll _n;
    ll _s;
};

void solve() {
    int M;
    cin >> M;

    ll ret = 0;
    repeat(_, M) {
        int n, s;
        cin >> n >> s;
        ModularSection m(n, s);

        ret += m.mod;
        ret %= X;
    }

    cout << ret << endl;
}
