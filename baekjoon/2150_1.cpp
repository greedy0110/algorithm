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

int n, m, cnt = 0;
vvi g;
vi dfsn;
vb finished; // scc 분리가 종료되었는가?
stack<int> s;
vvi scc;

// n 정점에서 도달 가능한 제일 높은(작은) 정점을 반환한다.
int dfs(int u) {
    dfsn[u] = ++cnt;
    s.push(u);

    // 지금 정점, 그리고 자식 정점들 에서 도달가능한 가장 높은 정점을 반환한다.
    int result = dfsn[u];
    for (int v : g[u]) {
        if (dfsn[v] == -1) {
            // 방문안했으면, 방문하자.
            result = min(result, dfs(v));
        } else if (!finished[v]) {
            // 이 전에 이미 도달한 (조상) && scc 로 추출되지 않은 것.
            result = min(result, dfsn[v]);
        }
    }

    // scc 추출함.
    if (result == dfsn[u]) {
        vi curScc;
        while (true) {
            int t = s.top();
            s.pop();
            curScc.push_back(t);
            finished[t] = true;
            if (t == u) break;
        }
        sort(all(curScc));
        scc.push_back(curScc);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    g = vvi(n + 1);
    dfsn = vi(n + 1, -1);
    finished = vb(n + 1, false);

    RP(_, m) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (dfsn[i] == -1) {
            dfs(i);
        }
    }

    sort(all(scc));

    cout << scc.size() << endl;
    for (auto &c : scc) {
        for (int u : c) cout << u << " ";
        cout << -1 << endl;
    }

    return 0;
}
