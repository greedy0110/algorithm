//
// Created by 신승민 on 2021/04/23.
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

int main() {
    cin >> N;

    vi A(N);
    // bj - j pair
    map<int, int> S;

    repeat(i, N) cin >> A[i];
    repeat(j, N) {
        int bj;
        cin >> bj;
        S[bj] = j;
    }

    // J 의 증가하는 부분 수열을 구하면 된다. (lis)
    vi vt;

    repeat(i, N) {
        int j_index = S[A[i]];

        if (vt.empty() || j_index > vt.back()) {
            vt.push_back(j_index);
        } else {
            int pos = lower_bound(all(vt), j_index) - vt.begin();
            vt[pos] = j_index;
        }
    }

    cout << vt.size() << endl;
}
