//
// Created by 신승민 on 2021/07/29.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

vector<int> G[1001];
vector<bool> V;

void dfs(int u) {
    V[u] = true;
    for (int v : G[u]) {
        if (V[v]) continue;
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    RP(_, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;

    V = vector<bool>(N, false);
    for (int i = 0; i < N; i++) {
        if (V[i]) continue;
        ans++;
        dfs(i);
    }
    cout << ans << endl;

    return 0;
}
