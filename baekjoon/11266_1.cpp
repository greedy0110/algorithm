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
stack<pii> dfs_s;
vector<vector<pii>> bcc;
vi bcc_counter;

void init_g() {
    g = vvi(n);
    dfs_n = vi(n, -1);
    bcc_counter = vi(n, 0);
    bcc.clear();
}

int build_bcc(int u, int prev = -1) {
    dfs_n[u] = ++cnt;
    int result = dfs_n[u];

    for (int v: g[u]) {
        if (v == prev) continue;

        if (dfs_n[u] > dfs_n[v]) dfs_s.push({u, v});
        // 역방향 간선.
        if (dfs_n[v] > 0) result = min(result, dfs_n[v]);
            // 트리 간선
        else {
            int temp = build_bcc(v, u);
            result = min(result, temp);
            // v가 DFS 트리상, u의 조상 노드로 갈 수 없음 -> 새 BCC 발견
            if (temp >= dfs_n[u]) {
                vector<pii> curBcc;
                set<int> curRelative;
                while (true) {
                    auto &t = dfs_s.top();
                    curRelative.insert(t.first);
                    curRelative.insert(t.second);
                    dfs_s.pop();
                    curBcc.push_back(t);
                    if (t == pii(u, v))break;
                }
                bcc.push_back(curBcc);
                for (int i : curRelative) bcc_counter[i]++;
            }
        }
    }
    return result;
}

void build() {
    for (int i = 0; i < n; i++) {
        if (dfs_n[i] == -1) {
            build_bcc(i);
        }
    }
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

    vi ans;
    for (int i = 0; i < n; i++) {
        // 서로다른 bcc에서 2번 이상 나타나면 단절점이다.
        if (bcc_counter[i] >= 2) ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    sort(all(ans));
    for (int i : ans) cout << i << " ";
    cout << endl;

    return 0;
}
