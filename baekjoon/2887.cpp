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

vector<tuple<int, int, int>> pos;

int dist(int u, int v) {
    int x1, y1, z1, x2, y2, z2;
    tie(x1, y1, z1) = pos[u];
    tie(x2, y2, z2) = pos[v];
    return min(abs(x1 - x2), min(abs(y1 - y2), abs(z1 - z2)));
}

void add_edges(vector<Edges> &es, vector<pair<int, int>> &xu) {
    sort(all(xu));
    for (int i = 0; i < (int) xu.size() - 1; i++) {
        int u = xu[i].second, v = xu[i + 1].second;
        es.push_back({dist(u, v), u, v});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> xu;
    vector<pair<int, int>> yu;
    vector<pair<int, int>> zu;
    RP(i, n) {
        int x, y, z;
        cin >> x >> y >> z;
        pos.emplace_back(x, y, z);
        xu.emplace_back(x, i);
        yu.emplace_back(y, i);
        zu.emplace_back(z, i);
    }

    vector<Edges> es;
    add_edges(es, xu);
    add_edges(es, yu);
    add_edges(es, zu);
    sort(all(es));

    UnionFind uf(n);

    ll ans = 0;
    for (auto &e: es) {
        if (!uf.same(e.v, e.u)) {
            uf.merge(e.v, e.u);
            ans = ans + (ll) e.w;
        }
    }
    cout << ans << endl;

    return 0;
}
