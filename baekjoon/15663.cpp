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

vi arr;
vb visited;
set<vi> already_found;
int N, M;

void comb(vi &ret, int k) {
    if (ret.size() == k) {
        if (already_found.find(ret) == already_found.end()) {
            already_found.insert(ret);
            printvi(ret);
        }
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        ret.push_back(arr[i]);
        comb(ret, k);
        ret.pop_back();
        visited[i] = false;
    }
}

void solve() {
    cin >> N >> M;

    arr = vi(N + 1);
    visited = vb(N + 1, false);

    repeat(i, N) {
        cin >> arr[i + 1];
    }

    sort(all(arr));

    vi ret;
    comb(ret, M);
}

