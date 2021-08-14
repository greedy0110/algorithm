//
// Created by 신승민 on 2021/08/14.
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

using Graph = vector<vector<pair<int, int>>>;

int N, M, A, B;
Graph G;

bool f(int X) {
    queue<int> q;
    vb visited(N, false);
    visited[A] = true;
    q.push(A);

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        for (auto &uc : G[c]) {
            int u = uc.first;
            int w = uc.second;

            if (w < X) continue;
            if (visited[u]) continue;

            visited[u] = true;
            q.push(u);
        }
    }

    return visited[B];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int max_c = -1;
    cin >> N >> M;
    G = Graph(N);
    RP(_, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
        max_c = max(max_c, c);
    }
    cin >> A >> B;
    A--;
    B--;

    int left = 1, right = max_c;
    while (left != right) {
        int mid = (left + right + 1) / 2;
        if (f(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << left << endl;

    return 0;
}
