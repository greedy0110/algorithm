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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vvi g(n + 1);
    vector<vector<pair<int, int>>> rg(n + 1);
    vi ind(n + 1, 0);
    vvi memo(n + 1, vi(n + 1, 0));
    RP(_, m) {
        int v, u, w;
        cin >> v >> u >> w;
        g[u].push_back(v);
        rg[v].push_back({u, w});
        ind[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            memo[i][i] = 1;
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

    for (int v : order) {
        for (auto &p : rg[v]) {
            int u = p.first;
            int w = p.second;

            // memo[v] 갱신 memo[u] 의 모든 요소를 w 배 곱해서 더해주자.
            for (int i = 1; i <= n; i++) {
                memo[v][i] += memo[u][i] * w;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int part = memo[n][i];
        if (part != 0) {
            cout << i << " " << part << endl;
        }
    }

    return 0;
}
