//
// Created by 신승민 on 2021/09/18.
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

class UnionFind {
public:
    vi parents;

    UnionFind(int n) {
        parents = vi(n);
        RP(i, n) parents[i] = i;
    }

    int find(int u) {
        if (u == parents[u]) return u;
        return parents[u] = find(parents[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        parents[u] = v;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    RP(_, m) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a - 1, b - 1});
    }
    sort(all(edges));
    UnionFind uf(n);
    int ans = 0;
    for (auto &edge: edges) {
        int c, u, v;
        tie(c, u, v) = edge;
        if (!uf.same(u, v)) {
            uf.merge(u, v);
            ans += c;
        }
    }
    cout << ans << endl;

    return 0;
}
