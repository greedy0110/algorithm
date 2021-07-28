//
// Created by 신승민 on 2021/07/29.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

vector<vector<int>> G;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    cout << u + 1 << " ";
    for (int v : G[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
}

void bfs(int st) {
    queue<int> q;
    visited[st] = true;
    cout << st + 1 << " ";
    q.push(st);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : G[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            cout << v + 1 << " ";
            q.push(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;
    V--;
    G = vector<vector<int>>(N);
    RP(_, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    RP(i, N) {
        sort(all(G[i]));
    }

    visited = vector<bool>(N, false);
    dfs(V);
    cout << endl;

    visited = vector<bool>(N, false);
    bfs(V);
    cout << endl;

    return 0;
}
