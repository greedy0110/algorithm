//
// Created by 신승민 on 2021/07/31.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

struct Edge {
    int v;
    int w;
};

struct Diameter {
    int diameter;
    int height;
};

int N;
vector<vector<Edge>> G;
vb V;

Diameter post_order(int from) {
    V[from] = true;

    vector<Edge> children;
    for (auto &e : G[from]) {
        if (V[e.v]) continue;
        children.push_back(e);
    }

    if (children.empty()) {
        return {0, 0};
    }

    if (children.size() == 1) {
        auto e = children.back();
        auto c = post_order(e.v);
        int nh = c.height + e.w;
        int nd = max(c.diameter, nh);
        return {nd, nh};
    }

    vector<int> ds;
    vector<int> hs;
    for (auto &e : children) {
        auto c = post_order(e.v);
        ds.push_back(c.diameter);
        hs.push_back(c.height + e.w);
    }

    sort(all(hs));
    int nh = hs.back();

    int nd1 = hs[hs.size() - 1] + hs[hs.size() - 2];
    int nd2 = *max_element(all(ds));

    return {max(nd1, nd2), nh};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    G = vector<vector<Edge>>(N);
    V = vb(N, false);
    RP(_, N) {
        int u, v, w;
        cin >> u;
        u--;

        while (true) {
            cin >> v;
            if (v == -1) break;
            cin >> w;
            v--;
            G[u].push_back({v, w});
        }
    }

    auto ans = post_order(0);
    cout << ans.diameter << endl;

    return 0;
}
