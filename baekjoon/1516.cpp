//
// Created by 신승민 on 2021/09/19.
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

vvi g;
vi costs;

void solve(int s, vi &dist) {
    for (int v: g[s]) {
        dist[v] = max(dist[v], dist[s] + costs[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    g = vvi(n);
    costs = vi(n);
    vi dist(n, 0);
    vi ind(n, 0);
    RP(i, n) {
        cin >> costs[i];
        dist[i] = costs[i];

        int v;
        while (true) {
            cin >> v;
            if (v == -1) break;
            v--;
            g[v].push_back(i);
            ind[i]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    vi order;
    for (int i = 0; i < n; i++) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : g[u]) {
            ind[v]--;
            if (ind[v] == 0) q.push(v);
        }
    }

    for (int i : order) {
        solve(i, dist);
    }

    for (int d : dist) {
        cout << d << endl;
    }

    return 0;
}
