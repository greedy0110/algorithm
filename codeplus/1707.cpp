//
// Created by 신승민 on 2021/07/29.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

vector<vector<int>> G;
vector<int> colors;
int V, E;

// 1, 2
bool dfs(int u, int color) {
    colors[u] = color;
    for (int v : G[u]) {
        if (colors[v] == 0) {
            if (!dfs(v, 3 - color)) return false;
        } else if (color == colors[v]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> V >> E;

        G = vector<vector<int>>(V);
        colors = vector<int>(V, 0);

        RP(_, E) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        bool ok = true;
        for (int i = 0; i < V; i++) {
            if (colors[i] != 0) continue;
            if (!dfs(i, 1)) {
                ok = false;
                break;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
