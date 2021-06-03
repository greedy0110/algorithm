//
// Created by 신승민 on 2021/06/03.
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
typedef vector<vc> vvc;
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

int N;
int R[501];
int C[501];
ll cache[501][501] = {0};

ll min_op(int x, int y) {
    // [x, y] 범위 내에서 최소 연산 값 반환
    if (x == y) return 0;

    ll &cac = cache[x][y];
    if (cac != 0) return cac;

    ll ret = (ll(1) << 31) - 1;
    for (int i = x; i < y; i++) {
        // [x, i], [i+1, y] 각각의 최소 연산 값 합
        ret = min(ret, min_op(x, i) + min_op(i + 1, y) + R[x] * C[i] * C[y]);
    }

    return cac = ret;
}

void solve() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d %d", &R[i], &C[i]);

    printf("%lld\n", min_op(0, N - 1));
}
