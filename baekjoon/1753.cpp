//
// Created by 신승민 on 2021/04/04.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <set>

using namespace std;

#define all(X) begin((X)), end((X))
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define BIG 987654321

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef priority_queue<int, vi, greater<>> mq;

vvpii wG;
int V, E, K;
vi dist;
si Q;

void dijkstra(int src) {
    dist = vi(V + 1, BIG);
    Q.clear();
    for (int i = 1; i <= V; i++) Q.insert(i);

    dist[src] = 0;

    while (!Q.empty()) {
        int v;
        int min_dist = BIG + 1;
        for (auto &i : Q) {
            if (dist[i] < min_dist) {
                v = i;
                min_dist = dist[i];
            }
        }

        Q.erase(v);

        for (int i = 0; i < wG[v].size(); i++) {
            int u = wG[v][i].fi;
            int w = wG[v][i].se;

            if (dist[v] + w < dist[u]) dist[u] = dist[v] + w;
        }
    }
}

void solve() {
    cin >> V >> E >> K;

    wG = vvpii(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        wG[u].push_back(make_pair(v, w));
    }

    dijkstra(K);

    for (int i = 1; i <= V; i++) {
        if (dist[i] == BIG) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
