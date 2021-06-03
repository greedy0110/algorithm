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

typedef struct Point {
    int a;
    int b;
    int c;
} Point;


void solve() {
    int N;
    scanf("%d", &N);
    vll A(N);

    repeat(i, N) scanf("%lld", &A[i]);

    sort(all(A));

    Point pt{0, 1, 2};
    int left, right;
    ll ret = 3000000001;
    for (int i = 0; i < N - 2; i++) {
        left = i + 1;
        right = N - 1;

        while (left < right && left < N && right < N) {
            ll temp = A[i] + A[left] + A[right];
            if (ret > abs(temp)) {
                ret = abs(temp);
                pt = {i, left, right};
            }
            if (temp > 0) right--;
            else if (temp < 0) left++;
            else break;
        }
    }

    printf("%lld %lld %lld\n", A[pt.a], A[pt.b], A[pt.c]);
}
