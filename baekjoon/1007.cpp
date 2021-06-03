//
// Created by 신승민 on 2021/06/03.
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

int T, N;
ll X[21];
ll Y[21];

double minsize(int i, ll accx, ll accy, int cnt_pos) {
    if (i == N) {
        if (cnt_pos == 0) return accx * accx + accy * accy;
        return SUPER_BIG;
    }

    double ret = SUPER_BIG;

    if (cnt_pos > 0) {
        // i 번째 점은 더해주는 경우.
        ret = minsize(i + 1, accx + X[i], accy + Y[i], cnt_pos - 1);
    }
    // i 번째 점은 빼놓는 경우.
    ret = min(ret, minsize(i + 1, accx - X[i], accy - Y[i], cnt_pos));

    return ret;
}

void solve() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%lld %lld", &X[i], &Y[i]);
        printf("%.12lf\n", sqrt(minsize(0, 0, 0, N / 2)));
    }
}