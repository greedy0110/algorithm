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
ll S;
vi A;

void ans2(int sum, int index, int end, vector<ll> &ret) {
    if (index == end) {
        ret.push_back(sum);
        ret.push_back(sum + A[index]);
        return;
    }

    ans2(sum + A[index], index + 1, end, ret);
    ans2(sum, index + 1, end, ret);
}

int main() {
    cin >> N >> S;
    A = vi(N);

    repeat(i, N) {
        cin >> A[i];
    }

    if (N == 1) {
        cout << ((A[0] == S) ? 1 : 0) << endl;
        return 0;
    }

    vll ret1, ret2;
    ans2(0, 0, N / 2 - 1, ret1);
    ans2(0, N / 2, N - 1, ret2);

    // O(NlogN), N = 10**6
    sort(all(ret1));
    sort(all(ret2));

    ll retc = 0;
    repeat(i, ret1.size()) {
        // let's find ret1[i] + ret2[j] == S
        ll need = S - ret1[i];
        retc += upper_bound(all(ret2), need) - lower_bound(all(ret2), need);
    }

    // if S == 0, then minus empty set.
    if (S == 0) retc--;

    cout << retc << endl;

    return 0;
}