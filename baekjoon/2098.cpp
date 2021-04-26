//
// Created by 신승민 on 2021/04/26.
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

int cache[0xffff + 1][16] = {};
int wG[16][16];
int N;

int key(vb &visited) {
    int mask = 0;
    repeat(i, N) {
        if (visited[i]) mask |= (1 << i);
    }
    return mask;
}

// if visited node, and current node is src
// then, return what the minimum length to 0 node.
int sol(vb &visited, int src) {
    if (all_of(all(visited), [](bool elem) { return elem; })) {
        if (wG[src][0] == 0) return BIG;
        return wG[src][0];
    }

    int &ret = cache[key(visited)][src];

    if (ret != 0) {
        return ret;
    }

    int ans = BIG;
    repeat(i, N) {
        if (visited[i]) continue;
        if (wG[src][i] == 0) continue;

        visited[i] = true;
        ans = min(ans, sol(visited, i) + wG[src][i]);
        visited[i] = false;
    }

    return ret = ans;
}

void solve() {
    cin >> N;
    repeat(i, N) {
        repeat(j, N) {
            cin >> wG[i][j];
        }
    }

    vb visited(N);
    visited[0] = true;

    int ans = BIG;
    repeat(i, N) {
        if (wG[0][i] == 0)continue;

        visited[i] = true;
        ans = min(ans, sol(visited, i) + wG[0][i]);
        visited[i] = false;
    }

    cout << ans << endl;
}
