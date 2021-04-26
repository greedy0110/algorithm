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

void solve() {
    int N;
    cin >> N;
    vi A(N);

    repeat(i, N) cin >> A[i];

    ll ans = SUPER_BIG;
    int st, ed;
    repeat(i, N) {
        int lb = lower_bound(all(A), -A[i]) - A.begin();

        if (i == lb) continue;

        if (lb != N && A[lb] == -A[i]) {
            if (A[lb] > A[i]) swap(A[lb], A[i]);
            cout << A[lb] << " " << A[i] << endl;
            return;
        }

        if (lb != N && abs(A[i] + A[lb]) < ans) {
            st = i;
            ed = lb;
            ans = abs(A[i] + A[lb]);
        }

        if (lb != 0 && i != lb - 1 && abs(A[i] + A[lb - 1]) < ans) {
            st = i;
            ed = lb - 1;
            ans = abs(A[i] + A[lb - 1]);
        }
    }

    if (st > ed) swap(st, ed);

    cout << A[st] << " " << A[ed] << endl;
}