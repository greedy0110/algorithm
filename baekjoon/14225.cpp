//
// Created by 신승민 on 2021/04/25.
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

int N;
vi S;

void p(int sum, int index, vi &ret) {
    if (index == N - 1) {
        ret.push_back(sum + S[index]);
        ret.push_back(sum);
        return;
    }

    p(sum + S[index], index + 1, ret);
    p(sum, index + 1, ret);
}

void solve() {
    cin >> N;
    S = vi(N);
    repeat(i, N) cin >> S[i];

    vi ret;
    p(0, 0, ret);

    sort(all(ret));

    int prev = -1, req = 1;
    repeat(i, ret.size()) {
        if (ret[i] == 0) continue;
        if (prev == ret[i]) continue;

        if (req != ret[i]) {
            cout << req << endl;
            return;
        }
        req++;
        prev = ret[i];
    }

    cout << req << endl;
}
