//
// Created by 신승민 on 2021/09/15.
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

int n;
vi w;
vvi g, children, cache, parents;

int solve(int cur, int p) {
    int &ret = cache[cur][p];
    if (ret != -1) return ret;

    int unpick = 0, pick = -1;
    for (int c : children[cur]) {
        unpick += solve(c, 0);
    }
    if (p == 0) {
        pick = w[cur];
        for (int c: children[cur]) {
            pick += solve(c, 1);
        }
    }
    return ret = max(unpick, pick);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    w = vi(n + 1);
    g = vvi(n + 1);
    children = vvi(n + 1);
    parents = vvi(n + 1);
    cache = vvi(n + 1, vi(2, -1));

    RP(i, n) cin >> w[i + 1];
    RP(_, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vb visited(n + 1, false);
    queue<int> q;
    visited[1] = true;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int v : g[cur]) {
            if (visited[v]) continue;
            children[cur].push_back(v);
            parents[v].push_back(cur);
            visited[v] = true;
            q.push(v);
        }
    }

    cout << solve(1, 0) << endl;



    return 0;
}
