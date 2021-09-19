//
// Created by 신승민 on 2021/09/18.
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
    vvi g(n + 1);
    vi indegree(n + 1, 0);
    RP(_, m) {
        int k, u;
        cin >> k >> u;
        RP(_, k - 1) {
            int v;
            cin >> v;
            g[u].push_back(v);
            indegree[v]++;
            u = v;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vi ans;
    // 위상 정렬
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            // 중간에 queue 가 비면 불가능.
            cout << 0 << endl;
            return 0;
        }

        int u = q.front();
        q.pop();
        ans.push_back(u);

        for (int v : g[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    for (int a : ans) {
        cout << a << endl;
    }

    return 0;
}
