//
// Created by 신승민 on 2021/04/13.
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

    vi arr = vi(N);
    vi d = vi(N);
    repeat(i, N) {
        scanf("%d", &arr[i]);
    }

    // vt[i] -> i개의 원소를 가진 IS 의 최소의 마지막 값
    vi vt;

    repeat(i, N) {
        int a = arr[i];

        if (vt.empty() || a > vt.back()) {
            vt.push_back(a);
            d[i] = vt.size();
        } else {
            int pos = lower_bound(all(vt), a) - vt.begin();
            vt[pos] = a;
            d[i] = pos + 1;
        }
    }

    int ma = vt.size();
    printf("%d\n", ma);

    vi ans;

    for (int i = N - 1; i >= 0; i--) {
        if (ma < 0) break;
        if (d[i] == ma) {
            ans.push_back(arr[i]);
            ma--;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}
