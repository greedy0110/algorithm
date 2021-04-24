//
// Created by 신승민 on 2021/04/24.
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

void solve() {
    int N, K;
    cin >> N >> K;
    vpii M(N);
    vi C(K);

    repeat(i, N) {
        int m, v;
        cin >> m >> v;
        M[i] = make_pair(m, v);
    }

    repeat(i, K) {
        cin >> C[i];
    }

    // 오름차순 정렬 전처리
    sort(all(M));
    sort(all(C));

    priority_queue<int, vi> MaxQ;

    int i = 0;
    ll ans = 0;
    repeat(j, K) {
        while (i < N && M[i].first <= C[j]) {
            MaxQ.push(M[i].second);
            i++;
        }

        if (!MaxQ.empty()) {
            ans += MaxQ.top();
            MaxQ.pop();
        }
    }

    cout << ans << endl;
}
