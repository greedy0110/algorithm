//
// Created by 신승민 on 2021/05/07.
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

int d[2001] = {};
vector<vi> cpd;
string S;
int N;

bool is_pd(int i, int j) {
    int &ans = cpd[i][j];
    if (ans != 0) {
        return (ans == 1);
    }

    while (i < j) {
        if (S[i] != S[j]) {
            ans = 2;
            return false;
        }
        i++;
        j--;
    }
    ans = 1;
    return true;
}

int p(int index) {
    if (index == N) return 0;

    // O(N)
    int &ans = d[index];
    if (ans != 0) return ans;

    int ret = BIG;
    for (int end = index; end < N; end++) { // O(N)
        if (is_pd(index, end)) {
            ret = min(ret, p(end + 1) + 1);
        }
    }

    return ans = ret;
}

void solve() {
    cin >> S;
    N = S.size();
    cpd = vector<vi>(N, vi(N, 0));

    cout << p(0) << endl;
}
