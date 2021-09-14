//
// Created by 신승민 on 2021/09/14.
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

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n, vb(n, false));
    RP(_, m) {
        int a, b;
        cin >> a >> b;
        g[a - 1][b - 1] = true;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // i->j 원래 갈 수 있거나, k를 거치면 이동할 수 있는 경우.
                g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
            }
        }
    }

    int s;
    cin >> s;
    RP(_, s) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int ans;
        if (!g[a][b] && !g[b][a]) ans = 0;
        else if (g[a][b]) ans = -1;
        else if (g[b][a]) ans = 1;
        else {
            assert(false);
        }
        cout << ans << endl;
    }

    return 0;
}
