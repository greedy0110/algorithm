//
// Created by 신승민 on 2021/04/07.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <queue>
#include <cmath>
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

const ll m = 1000000000000000; // 0 이 15

class BigInteger {
public:
    ll h = 0;
    ll l = 0;
    bool visited = false;

    BigInteger operator+(const BigInteger &other) const {
        BigInteger ret;

        ret.h = h + other.h;
        ret.l = l + other.l;

        if (ret.l >= m) {
            ret.h += 1;
            ret.l -= m;
        }

        return ret;
    };

    void print() const {
        if (h != 0) {
            vi h_factors;
            ll th = h;
            while (th != 0) {
                h_factors.push_back(th % 10);
                th /= 10;
            }
            vi l_factors(log10(m), 0);
            ll tl = l;

            for (int i = log10(m) - 1; i >= 0 && tl != 0; i--) {
                l_factors[i] = tl % 10;
                tl /= 10;
            }

            reverse(all(h_factors));
            for (int h_factor : h_factors) cout << h_factor;
            for (int l_factor : l_factors) cout << l_factor;

            cout << endl;
        } else {
            cout << l << endl;
        }
    }
};

BigInteger cache[101][101];

BigInteger comb(int n, int k) {
    if (k == 0) return BigInteger{0, 1};
    if (k == n) return BigInteger{0, 1};
    if (n < k) return BigInteger{0, 0};

    BigInteger &ans = cache[n][k];
    if (ans.visited) return ans;

    ans = comb(n - 1, k - 1) + comb(n - 1, k);
    ans.visited = true;

    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;

    comb(n, m).print();
}
