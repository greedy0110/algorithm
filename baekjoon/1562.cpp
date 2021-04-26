//
// Created by 신승민 on 2021/04/26.
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
typedef vector<char> vc;
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

int M = 1000000000;
int C[10][101][0x3ff + 1] = {};
int N;

int key(const vb &visited) {
    int mask = 0;
    repeat(i, 10) {
        if (visited[i]) mask |= (1 << i);
    }
    return mask;
}

int p(int src, int n, vb &visited) {
    if (src < 0 || src > 9) return 0;
    if (n == 0) {
        if (all_of(all(visited), [](bool elem) { return elem; })) {
            return 1;
        } else return 0;
    }

    int &ret = C[src][n][key(visited)];
    if (ret != 0) return ret;

    int ans = 0;
    if (src - 1 >= 0) {
        if (!visited[src - 1]) {
            visited[src - 1] = true;
            ans += p(src - 1, n - 1, visited);
            visited[src - 1] = false;
        } else {
            ans += p(src - 1, n - 1, visited);
        }
    }

    if (src + 1 <= 9) {
        if (!visited[src + 1]) {
            visited[src + 1] = true;
            ans += p(src + 1, n - 1, visited);
            visited[src + 1] = false;
        } else {
            ans += p(src + 1, n - 1, visited);
        }
    }
    ans %= M;

    return ret = ans;
}

int tp(int N) {
    int ans = 0;
    vb visited(10, false);
    for (int src = 1; src < 10; src++) {
        visited[src] = true;
        ans += p(src, N - 1, visited);
        ans %= M;
        visited[src] = false;
    }
    return ans;
}

void solve() {
    cin >> N;

    cout << tp(N) << endl;
}
