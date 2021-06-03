//
// Created by 신승민 on 2021/05/10.
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
    scanf("%d", &N);
    vll A(N);

    repeat(i, N) scanf("%lld", &A[i]);

    sort(all(A));

    vi ret(3);
    ll min_d = 3000000001;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            // let's find k, which A[i] + A[j] + A[k] are the closest to 0. (i != j != k)
            // A[i] < A[j] < A[k]
            // i < j < k
            ll X = -(A[i] + A[j]);
            int ck = lower_bound(all(A), X) - A.begin();

            // 딱 맞는 인자가 존재하지 않고, 모든 값보다 클 때
            if (ck == N) {
                ck--;
                if (ck < N && min_d > abs(A[i] + A[j] + A[ck])) {
                    min_d = abs(A[i] + A[j] + A[ck]);
                    ret[0] = i;
                    ret[1] = j;
                    ret[2] = ck;
                }
                continue;
            }

            // 딱 맞는 인자가 존재하지 않고, 모든 값보다 작을 때

            // or 0 번에 해당 인자가 존재할 때, 그런데, 0 번에 해당 인자가 존재하는 경우
            // 0, i 의 값에서 이미 j를 탐색할 수 있었을 것이다.
            // 따라서 i != 0 이면, 이 값은 무시해도 된다.
            if (ck == 0) {
                ck = j + 1;
                if (ck < N && min_d > abs(A[i] + A[j] + A[ck])) {
                    min_d = abs(A[i] + A[j] + A[ck]);
                    ret[0] = i;
                    ret[1] = j;
                    ret[2] = ck;
                }
                continue;
            }

            if (ck <= j + 1) continue;

            if (ck < N && min_d > abs(A[i] + A[j] + A[ck])) {
                min_d = abs(A[i] + A[j] + A[ck]);
                ret[0] = i;
                ret[1] = j;
                ret[2] = ck;
            }

            ck -= 1;
            if (ck < N && min_d > abs(A[i] + A[j] + A[ck])) {
                min_d = abs(A[i] + A[j] + A[ck]);
                ret[0] = i;
                ret[1] = j;
                ret[2] = ck;
            }
        }
    }

    for (auto i : ret) {
        printf("%lld ", A[i]);
    }
    printf("\n");
}
