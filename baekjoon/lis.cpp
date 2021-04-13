//
// Created by 신승민 on 2021/04/13.
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
#define BIG 987654321
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

int N;
vi arr;

// cache[x]는, arr[x]를 포함한, lis 의 최대를 반환.
vi cache;

// sp를 포함한, lis 길이의 최대를 반환
int lis(int sp) {
    int &memo = cache[sp];
    if (memo != -1) return memo;

    int ans = 1;
    for (int i = sp + 1; i < N; i++) {
        if (arr[i] > arr[sp]) {
            ans = max(ans, lis(i) + 1);
        }
    }

    return memo = ans;
}

void solve() {
    cin >> N;
    arr = vi(N);
    cache = vi(N, -1);

    repeat(i, N) {
        cin >> arr[i];
    }

    int ans = 1;
    repeat(i, N) {
        ans = max(ans, lis(i));
    }

    cout << ans << endl;
}
