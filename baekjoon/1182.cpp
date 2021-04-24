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

int N;
int S;
vi A;

// deal with two cases, contain A[index] or not.
ll ans(vi &ret, int index) {
    if (index == N - 1) {
        int prev = accumulate(all(ret), 0);

        ll cnt = 0;
        // if ret is empty and not contain A[index], then it is empty set. so, it has to be ignored.
        if (prev == S && !ret.empty()) {
            cnt++;
        }
        if (prev + A[index] == S) {
            cnt++;
        }

        return cnt;
    }

    ll cnt = 0;

    // case: contain A[index]
    ret.push_back(A[index]);
    cnt += ans(ret, index + 1);
    ret.pop_back();

    // case: not contain
    cnt += ans(ret, index + 1);

    return cnt;
}

int main() {
    cin >> N >> S;
    A = vi(N);

    repeat(i, N) {
        cin >> A[i];
    }

    vi ret;
    cout << ans(ret, 0) << endl;

    return 0;
}