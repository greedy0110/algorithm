//
// Created by 신승민 on 2021/09/19.
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int k, m, p;
        cin >> k >> m >> p;
        vvi g(m + 1);
        vvi rg(m + 1); // reverse graph.
        vi ind(m + 1, 0);
        vi level(m + 1, 0);

        RP(_, p) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            rg[b].push_back(a);
            ind[b]++;
        }

        queue<int> q;
        for (int i = 1; i <= m; i++) {
            if (ind[i] == 0) {
                q.push(i);
                level[i] = 1;
            }
        }

        vi order;
        for (int i = 0; i < m; i++) {
            int u = q.front();
            q.pop();
            order.push_back(u);

            for (int v : g[u]) {
                ind[v]--;
                if (ind[v] == 0) q.push(v);
            }
        }

        for (int i = 0; i < m; i++) {
            int v = order[i];

            vi pls;
            for (int u : rg[v]) {
                pls.push_back(level[u]);
            }

            if (pls.empty()) continue;
            if (pls.size() == 1) {
                level[v] = pls.back();
                continue;
            }
            sort(all(pls));
            int a = pls.back();
            pls.pop_back();
            int b = pls.back();
            if (a == b) {
                level[v] = a + 1;
            } else {
                level[v] = a;
            }
        }

        cout << k << " " << *max_element(all(level)) << endl;
    }

    return 0;
}
