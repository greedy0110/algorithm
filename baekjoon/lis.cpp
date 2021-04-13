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
#define BIG 987654321
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

int N;
vi arr;

// dp[i] 는 arr[i] 를 마지막 요소로 하는 lis 의 길이
vi dp;

// prev_index[i] 는 arr[i] 이전의 lis 요소, -1 prev 가 없음.
vi prev_index;

void solve() {
    cin >> N;
    arr = vi(N);
    dp = vi(N, 1);
    prev_index = vi(N, -1);

    repeat(i, N) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        // dp[0..i-1] 까지는 valid 한 값이 들어있다.
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                // arr[i] 보다 작은 arr[j] 를 찾으면
                // dp[j] 에 해당하는 lis 에 arr[i] 를 추가할 수 있다.
                dp[i] = dp[j] + 1;
                prev_index[i] = j;
            }
        }
    }

    auto iter = max_element(all(dp));
    int index = distance(dp.begin(), iter);

    cout << *iter << endl;

    vi r;
    r.push_back(arr[index]);

    int route = prev_index[index];
    while (route != -1) {
        r.push_back(arr[route]);
        route = prev_index[route];
    }

    for (int i = r.size() - 1; i >= 0; i--) {
        cout << r[i] << " ";
    }
    cout << endl;
}
