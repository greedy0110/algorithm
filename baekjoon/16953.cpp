//
// Created by 신승민 on 2021/04/11.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <queue>
#include <numeric>
#include <set>
#include <map>

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

void printvi(const vi &v, string deli = " ") {
    for (auto i : v) {
        cout << i << deli;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

int bfs(int a, int b) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;

    q.push(make_pair(a, 0));

    int ans = -1;
    while (!q.empty()) {
        auto value = q.top();
        q.pop();

        ll na = value.first;
        int dist = value.second;

        if (na == b) {
            ans = dist + 1;
            break;
        }
        if (na > b) { break; }

        q.push(make_pair(na * 2, dist + 1));
        q.push(make_pair(10 * na + 1, dist + 1));
    }

    return ans;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << bfs(a, b) << endl;
}
