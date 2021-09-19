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
        int n, m;
        cin >> n;
        vi ly(n);
        // g[a][b], a가 b를 이겼다.
        vvi g(n + 1, vi(n + 1, 0));
        vi ind(n + 1, 0);
        RP(i, n) cin >> ly[i];


        for (int i = 0; i < n; i++) {
            int u = ly[i];
            for (int j = i + 1; j < n; j++) {
                int v = ly[j];
                g[u][v] = 1; // 앞에 리스트는, 뒤의 요소를 이긴다.
                ind[v]++;
            }
        }

        cin >> m;

        RP(_, m) {
            int a, b;
            cin >> a >> b; // a,b 가 반대로 뒤집히자.
            if (g[b][a] == 1) {
                g[b][a] = 0;
                ind[a]--;
                g[a][b] = 1;
                ind[b]++;
            } else {
                g[b][a] = 1;
                ind[a]++;
                g[a][b] = 0;
                ind[b]--;
            }
        }

        // 위상정렬.
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (ind[i] == 0) q.push(i);
        }

        vi ans;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (q.empty()) {
                // 다 완성되기 전에 Q가 빈다면, 사이클이 있는 것이다.
                ok = false;
                break;
            }

            int u = q.front();
            q.pop();
            ans.push_back(u);

            for (int j = 1; j <= n; j++) {
                if (g[u][j] == 1) {
                    ind[j]--;
                    if (ind[j] == 0) q.push(j);
                }
            }
        }
        if (!ok) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        for (int a : ans) cout << a << " ";
        cout << endl;
    }

    return 0;
}
