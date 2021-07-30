//
// Created by 신승민 on 2021/07/30.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

vvi G;
vb V;
vi ret;

void dfs(int u) {
    V[u] = true;
    ret.push_back(u);

    for (int v : G[u]) {
        if (V[v]) continue;
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    G = vvi(N);
    V = vb(N, false);
    RP(_, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vi ans(N);
    vi order(N);
    RP(i, N) {
        cin >> ans[i];
        ans[i]--;
        order[ans[i]] = i;
    }

    RP(i, N) {
        sort(all(G[i]), [&](const int &u, const int &v) {
            return order[u] < order[v];
        });
    }

    dfs(0);

    if (ans == ret) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
