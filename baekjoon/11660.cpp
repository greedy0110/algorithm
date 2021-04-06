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

using namespace std;

#define all(X) begin((X)), end((X))
#define sz(X) (int)(X).size()
#define fi first
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
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

int N, M;
vvll cache;

void solve() {
    cin >> N >> M;
    cache = vvll(N + 1, vll(N + 1));

    int k;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> k;
            if (i == 1 && j == 1) cache[i][j] = k;
            else if (i == 1) cache[i][j] = cache[i][j - 1] + k;
            else if (j == 1) cache[i][j] = cache[i - 1][j] + k;
            else cache[i][j] = cache[i][j - 1] + cache[i - 1][j] - cache[i - 1][j - 1] + k;
        }
    }

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll big = cache[x2][y2];
        ll top = cache[x2][y1 - 1];
        ll left = cache[x1 - 1][y2];
        ll small = cache[x1 - 1][y1 - 1];

        // cout 으로 100,000 번 출력하려니까 시간 초과 난다...
        printf("%lld\n", big - (left + top - small));
    }
}