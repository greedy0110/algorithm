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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

vi items;
vvpii wG;
int N, M, R;

int dijkstra(int src) {
    vi dist(N + 1, BIG);
    mpq min_q;

    dist[src] = 0;
    min_q.push(make_pair(0, src));

    while (!min_q.empty()) {
        auto value = min_q.top();
        min_q.pop();
        int d = value.first;
        int u = value.second;

        for (int i = 0; i < wG[u].size(); i++) {
            int v = wG[u][i].first;
            int w = wG[u][i].second;

            if (d + w < dist[v]) {
                dist[v] = d + w;
                min_q.push(make_pair(dist[v], v));
            }
        }
    }

    int ret = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= M) {
            ret += items[i];
        }
    }

    return ret;
}

void solve() {
    cin >> N >> M >> R;

    items = vi(N + 1);
    wG = vvpii(N + 1);

    repeat(i, N) {
        cin >> items[i + 1];
    }

    repeat(_, R) {
        int a, b, w;
        cin >> a >> b >> w;

        wG[a].push_back(make_pair(b, w));
        wG[b].push_back(make_pair(a, w));
    }

    int ret = -1;
    for (int u = 1; u <= N; u++) {
        ret = max(ret, dijkstra(u));
    }

    cout << ret << endl;
}
