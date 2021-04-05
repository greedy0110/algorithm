//
// Created by 신승민 on 2021/04/05.
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
typedef priority_queue<pii, vpii, greater<>> mpq;

vvpii nwG;
vi dist;
int V, E, W;
bool has_negative_cycle = false;
vb visited;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

void bellman_ford(int src) {
    dist = vi(V + 1, BIG);
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (int u = 1; u <= V; u++) {
            for (auto &edge : nwG[u]) {
                int v = edge.fi;
                int w = edge.se;

                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    for (int u = 1; u <= V; u++) {
        for (auto &edge : nwG[u]) {
            int v = edge.fi;
            int w = edge.se;

            if (dist[u] + w < dist[v]) {
                has_negative_cycle = true;
                return;
            }
        }
    }
}

void solve() {
    int T;
    cin >> T;

    while (T--) {
        cin >> V >> E >> W;

        nwG = vvpii(V + 1);

        for (int i = 0; i < E; i++) {
            int s, e, t;
            cin >> s >> e >> t;

            nwG[s].push_back(make_pair(e, t));
            nwG[e].push_back(make_pair(s, t));
        }

        for (int i = 0; i < W; i++) {
            int s, e, t;
            cin >> s >> e >> t;

            nwG[s].push_back(make_pair(e, -t));
        }

        has_negative_cycle = false;
        visited = vb(V + 1, false);
        for (int i = 1; i <= V; i++) {
            if (visited[i]) continue;

            bellman_ford(i);

            for (int j = 1; j <= V; j++) {
                visited[j] = dist[j] != BIG;
            }

            if (has_negative_cycle) {
                break;
            }
        }
        cout << (has_negative_cycle ? "YES" : "NO") << endl;
    }
}