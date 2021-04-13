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

void solve() {
    scanf("%d", &N);

    vi lis;
    repeat(i, N) {
        int a;
        scanf("%d", &a);

        if (lis.empty()) lis.push_back(a);
        else if (a > lis.back()) lis.push_back(a);
        else {
            auto iter = lower_bound(all(lis), a);
            *iter = a;
        }
    }

    printf("%d\n", lis.size());
}
