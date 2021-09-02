//
// Created by 신승민 on 2021/09/01.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'
#define custom_pq(X) priority_queue<X, vector<X>, X>

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

typedef pair<int, int> pii;

int N, M;
vector<vector<pair<int, int>>> G;

int dijkstra(int s, int e) {
    // dist, node (가장 작은 dist 부터 순회하기 위해서)
    priority_queue<pii, vector<pii>, greater<>> q;
    vector<int> dist(N, 1e9);
    vb visited(N, false);
    dist[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        int cd = q.top().first;
        int u = q.top().second;
        q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &vc : G[u]) {
            int v = vc.first;
            int c = vc.second;
            if (dist[v] > cd + c) {
                dist[v] = cd + c;
                q.push({dist[v], v});
            }
        }
    }
    return dist[e];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    G = vector<vector<pii>>(N);
    vvi W(N, vi(N, 1e9));
    RP(_, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b, c});
    }

    int s, e;
    cin >> s >> e;

    cout << dijkstra(s - 1, e - 1) << endl;

    return 0;
}
