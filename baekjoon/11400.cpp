//
// Created by 신승민 on 2021/09/22.
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

int n, m, cnt;
vvi g;
vi dfs_n;
set<pii> ans;

void init_g() {
    g = vvi(n);
    dfs_n = vi(n, -1);
    cnt = 0;
}

int build_bcc(int u, int prev = -1) {
    // u 로부터 도달할 수 있는 가장 작은, 높은, 먼저 불린, 조상 노드의 번호
    int result = dfs_n[u] = ++cnt;
    for (int v : g[u]) {
        if (v == prev) continue;
        // 역방향 간선
        if (dfs_n[v] != -1) result = min(result, dfs_n[v]);
        else {
            // 트리 간선
            int sub = build_bcc(v, u);
            result = min(result, sub);

            // v 에서 u를 넘어서 그 조상으로 넘어가는 게 불가능함.
            // u -> v 를 이동했지만, v 에서 u 혹은, 넘어 갈 수 없다면?
            // v 에서 u 까지 도달할 수 없다면? u->v 가 단절선!
            if (sub > dfs_n[u]) {
                if (u > v) {
                    ans.insert({v, u});
                } else {
                    ans.insert({u, v});
                }
            }
        }
    }
    return result;
}

void build() {
    for (int i = 0; i < n; i++) if (dfs_n[i] == -1) build_bcc(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    init_g();
    RP(_, m) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    build();
    cout << ans.size() << endl;
    for (auto &a : ans) {
        cout << a.first + 1 << " " << a.second + 1 << endl;
    }

    return 0;
}
