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

vvi cache;
vvi arr;
int N;

int pm(int kind, int n) {
    if (n < 0) return 0;

    int &ans = cache[kind][n];

    if (ans != -1) return ans;

    if (kind == 0) ans = arr[0][n] + max(pm(1, n - 1), pm(2, n - 1));
    else if (kind == 1) ans = arr[1][n] + max(pm(0, n - 1), pm(2, n - 1));
    else ans = max(pm(0, n - 1), pm(1, n - 1));

    return ans;
}

void solve() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N;
        cache = vvi(3, vi(N, -1));
        arr = vvi(2, vi(N));

        for (int i = 0; i < N; i++) {
            cin >> arr[0][i];
        }

        for (int i = 0; i < N; i++) {
            cin >> arr[1][i];
        }

        cout << max(pm(0, N - 1), pm(1, N - 1)) << endl;
    }
}