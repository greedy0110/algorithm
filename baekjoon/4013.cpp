//
// Created by 신승민 on 2021/09/21.
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

vvi scc;
vi scc_id;
vb finished;
vi dfsn;
stack<int> dfs_stack;
int cnt = 0;
int cur_scc_id = 0;

int build_scc(int u) {
    dfsn[u] = ++cnt;
    dfs_stack.push(u);

    int result = dfsn[u];
    for (int v :g[u]) {
        if (dfsn[v] == -1) result = min(result, build_scc(v));
        else if (!finished[v]) result = min(result, dfsn[v]);
    }

    if (result == dfsn[u]) {
        vi curScc;
        while (true) {
            int t = dfs_stack.top();
            dfs_stack.pop();
            finished[t] = true;
            curScc.push_back(t);
            scc_id[t] = cur_scc_id;
            if (t == u) break;
        }
        scc.push_back(curScc);
        cur_scc_id++;
    }

    return result;
}

void build() {
    for (int i = 0; i < g.size(); i++) {
        if (dfsn[i] == -1) build_scc(i);
    }
}

struct Node {
    int cash = 0;
    bool end_point = false, can_reach = false;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // n, m = 5 * 10^5
    g = vvi(n); // O(n+m) -> 1M size, 4 byte
    vi cash(n);
    vb rests(n, false);
    scc_id = vi(n, -1);
    dfsn = vi(n, -1);
    finished = vb(n, false);
    RP(_, m) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }

    RP(i, n) cin >> cash[i];

    int s, p;
    cin >> s >> p;
    s--;
    RP(_, p) {
        int a;
        cin >> a;
        rests[a - 1] = true;
    }

    build();
    s = scc_id[s];
    int sn = scc.size();

    //TODO: impossible
//    vvi scc_g(sn, vi(sn, 0)); // O(n^2) -> 10^10
    vvi scc_g(sn);
    vector<Node> scc_node(sn);

    for (int u = 0; u < n; u++) {
        int uid = scc_id[u];

        scc_node[uid].cash += cash[u];
        if (rests[u]) scc_node[uid].end_point = true;

        auto &sg = scc_g[uid];
        for (int v : g[u]) {
            int vid = scc_id[v];
            if (uid == vid) continue;
            sg.push_back(vid);
        }
        sort(all(sg));
        sg.erase(unique(all(sg)), sg.end());
    }

    vi ind(sn, 0);
    for (int u = 0; u < sn; u++) {
        for (int v : scc_g[u]) {
            ind[v]++;
        }
    }

    vi ans(sn, 0);
    queue<int> q;
    for (int i = 0; i < sn; i++) {
        ans[i] = scc_node[i].cash;
        if (i == s) scc_node[i].can_reach = true;
        if (ind[i] == 0) q.push(i);
    }
    for (int i = 0; i < sn; i++) {
        int u = q.front();
        q.pop();
        for (int v : scc_g[u]) {
            if (scc_node[u].can_reach) {
                ans[v] = max(ans[v], ans[u] + scc_node[v].cash);
                scc_node[v].can_reach = true;
            }
            ind[v]--;
            if (ind[v] == 0) q.push(v);
        }
    }

    int ret = 0;
    for (int i = 0; i < sn; i++) {
        if (scc_node[i].can_reach && scc_node[i].end_point) ret = max(ret, ans[i]);
    }
    cout << ret << endl;

    return 0;
}
