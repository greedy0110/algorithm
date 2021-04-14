//
// Created by 신승민 on 2021/04/14.
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
    int n, s;
    cin >> n >> s;

    vi arr(n);
    repeat(i, n) cin >> arr[i];

    // p[i] = [0,i] 영역의 합, 오름차순 정렬
    vi p(n);
    p[0] = arr[0];
    for (int i = 1; i < n; i++) {
        p[i] = arr[i] + p[i - 1];
    }

    int ans = BIG;
    for (int i = 0; i < n; i++) {
        // [j,i] 영역의 합
        // p[i] - p[j-1] >= s 여야함.
        // p[j-1] 이 최대 여야함.
        // p[j-1] <= p[i] - s 여 야함.
        // 최대 p[i] - s 이고, 그보다 작을 수도 있음

        // j 의 위치 파악.
        int j = upper_bound(all(p), p[i] - s) - p.begin();
//        printf("%d %d %d %d\n", arr[i], p[i], i, j);
        if (j == 0) {
            if (p[i] >= s) {
                ans = min(ans, i + 1);
            }
            continue;
        }
        if (p[i] - p[j - 1] < s) continue;

        // [j+1...i] 의 합, s 이상이다.
        ans = min(ans, i - j + 1);
    }

    cout << ((ans == BIG) ? 0 : ans) << endl;
}
