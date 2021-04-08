//
// Created by 신승민 on 2021/04/08.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
typedef vector<string> vs;
typedef priority_queue<int, vi, greater<>> mq;
typedef priority_queue<pii, vpii, greater<>> mpq;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

int N, M, X;
vvpii wG;

int dijkstra(int src, int tgt) {
    if (src == tgt) return 0;

    vi dist(N + 1, BIG);

    mpq min_q;

    min_q.push(make_pair(0, src));

    while (!min_q.empty()) {
        pii value = min_q.top();
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

    return dist[tgt];
}

void solve() {
    cin >> N >> M >> X;

    wG = vvpii(N + 1, vpii());

    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;

        wG[u].push_back(make_pair(v, t));
    }

    int max_time = -1;
    for (int i = 1; i <= N; i++) {
        int t = dijkstra(i, X) + dijkstra(X, i);
        max_time = max(max_time, t);
    }

    cout << max_time << endl;
}
