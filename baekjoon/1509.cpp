//
// Created by 신승민 on 2021/06/06.
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
#define SUPER_BIG numeric_limits<double>::max()

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
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

vector<vb> is_pd_dp;
vi div_dp;
char A[2501];
int N;

int min_div(int st) {
    if (st >= N) return 0;

    int &cac = div_dp[st];
    if (cac != -1) return cac;

    int ret = INT_MAX;
    for (int j = st; j < N; j++) {
        if (!is_pd_dp[st][j]) continue;

        ret = min(ret, min_div(j + 1) + 1);
    }

    return cac = ret;
}

void solve() {
    scanf("%s", A);
    N = strlen(A);

    is_pd_dp = vector<vb>(N, vb(N, false));
    div_dp = vi(N, -1);

    for (int i = 0; i < N; i++) {
        is_pd_dp[i][i] = true;
        if (A[i] == A[i + 1]) {
            is_pd_dp[i][i + 1] = true;
        }
    }

    for (int i = 2; i < N; i++) {
        // i 는 거리
        for (int j = 0; j < N - i; j++) {
            // j 는 시작 index
            is_pd_dp[j][j + i] = A[j] == A[j + i] && is_pd_dp[j + 1][j + i - 1];
        }
    }

    printf("%d\n", min_div(0));
}
