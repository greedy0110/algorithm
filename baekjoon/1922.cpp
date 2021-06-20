//
// Created by 신승민 on 2021/06/20.
//

#include <bits/stdc++.h>

using namespace std;

#define all(X) begin((X)), end((X))
#define endl '\n'
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define repeat(i, X) for (int i=0; i<((X)); i++)
#define SUPER_BIG numeric_limits<double>::max()

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
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
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

class UnionFind {
public:
    UnionFind(int n) {
        ps = vi(n);
        lv = vi(n, 1);
        for (int i = 0; i < n; i++) {
            ps[i] = i;
        }
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (lv[a] > lv[b]) swap(a, b);
        assert(lv[a] <= lv[b]);

        ps[a] = b;

        if (lv[a] == lv[b]) lv[b]++;
    }

    int find(int a) {
        if (a == ps[a]) return a;
        return ps[a] = find(ps[a]);
    }

private:
    vi ps;
    vi lv;
};

typedef struct Edge {
    int u;
    int v;
    int weight;
} Edge;

bool compare(const Edge &e1, const Edge &e2) {
    return e1.weight < e2.weight;
}

void solve() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<Edge> es(M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &es[i].u, &es[i].v, &es[i].weight);
    }
    sort(all(es), compare);

    UnionFind uf(N + 1);

    int ans = 0;
    for (int i = 0; i < M; i++) {
        int u = es[i].u, v = es[i].v, w = es[i].weight;

        // u, v 가 이미 같은 집단이면 pass.
        u = uf.find(u);
        v = uf.find(v);
        if (u == v) continue;

        uf.merge(u, v);
        ans += w;
    }

    printf("%d\n", ans);
}
