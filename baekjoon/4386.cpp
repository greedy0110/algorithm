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
    float w;
    int u, v;

    bool operator<(Edges &a) { return w < a.w; }
};

float sqr_dist(pair<float, float> &a, pair<float, float> &b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<float, float>> pos;
    RP(_, n) {
        float a, b;
        cin >> a >> b;
        pos.push_back({a, b});
    }

    vector<Edges> es;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            float sqr = sqrt(sqr_dist(pos[i], pos[j]));
            es.push_back({sqr, i, j});
        }
    }

    sort(all(es));
    UnionFind uf(n);

    float mst = 0.0;
    for (auto &e :es) {
        if (!uf.same(e.v, e.u)) {
            uf.merge(e.v, e.u);
            mst += e.w;
        }
    }

    cout << mst << endl;

    return 0;
}
