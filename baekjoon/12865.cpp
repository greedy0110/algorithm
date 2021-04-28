//
// Created by 신승민 on 2021/04/28.
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

int N, K;
int R[100001][101] = {}, A[101], W[101], V[101];

int p(int remain, int index) {
    if (index == N) return 0;

    int &mem = R[remain][index];
    if (mem != -1) return mem;

    int ans = p(remain, index + 1);
    if (remain >= W[index])
        ans = max(ans, p(remain - W[index], index + 1) + V[index]);

    return mem = ans;
}

void solve() {
    cin >> N >> K;

    repeat(i, 100001) repeat(j, 101) R[i][j] = -1;

    repeat(i, N) {
        cin >> W[i] >> V[i];
    }

    cout << p(K, 0) << endl;
}
