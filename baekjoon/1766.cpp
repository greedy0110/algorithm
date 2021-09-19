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

    int n, m;
    cin >> n >> m;
    vvi g(n + 1);
    vi ind(n + 1, 0);
    RP(_, m) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        ind[b]++;
    }

    priority_queue<int, vi, greater<>> q; // 꺼낼 수 있는 것 중에 가장 작은 값을 꺼내자.
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) q.push(i);
    }

    vi order;
    for (int i = 0; i < n; i++) {
        int u = q.top();
        q.pop();
        order.push_back(u);

        for (int v : g[u]) {
            ind[v]--;
            if (ind[v] == 0) q.push(v);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << order[i] << " ";
    }
    cout << endl;

    return 0;
}
