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

struct Edges {
    int w, u, v;

    bool operator<(Edges &a) { return w < a.w; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0) break;
        vector<Edges> edges;
        int total = 0;
        RP(_, n) {
            int x, y, z;
            cin >> x >> y >> z;
            total += z;
            edges.push_back({z, x, y});
        }

        UnionFind uf(m);
        sort(all(edges));
        int mst = 0;
        for (auto &edge: edges) {
            if (!uf.same(edge.u, edge.v)) {
                uf.merge(edge.u, edge.v);
                mst += edge.w;
            }
        }

        cout << total - mst << endl;
    }

    return 0;
}
