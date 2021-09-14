//
// Created by 신승민 on 2021/09/15.
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

int n;
vvi g, children;
vvi cache;

int SNS(int cur, int pick_parent) {
    int &cac = cache[cur][pick_parent];
    if (cac != -1) return cac;

    // 부모가 선택 되었다면? cur은 선택하지 못한다.
    // 부모가 선택 안되었다면? cur을 선택하거나, 선택하지 않을 수 있다.

    // 자식을 선택한 경우.
    int notpick = 1e9, pick = 1;
    for (int child: children[cur]) {
        pick += SNS(child, 1);
    }
    if (pick_parent == 1) {
        // 부모가 선택되어있으면, 자식은 선택할 수 없다.
        notpick = 0;
        for (int child: children[cur]) {
            notpick += SNS(child, 0);
        }
    }
    return cac = min(notpick, pick);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    g = vvi(n + 1);
    children = vvi(n + 1);
    cache = vvi(n + 1, vi(2, -1));
    RP(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 1을 root로 해서 트리를 형성한다. bfs!
    vb visited(n + 1, false);
    queue<int> q;
    visited[1] = true;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int v : g[cur]) {
            if (visited[v]) continue;
            children[cur].push_back(v);
            visited[v] = true;
            q.push(v);
        }
    }
    cout << SNS(1, 1) << endl;
    return 0;
}
