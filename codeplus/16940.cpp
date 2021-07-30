//
// Created by 신승민 on 2021/07/30.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<bool> V(N, false);
    vector<int> ans(N);
    vector<int> order(N);
    RP(_, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    RP(i, N) {
        cin >> ans[i];
        ans[i]--;
        order[ans[i]] = i;
    }

    RP(i, N) {
        sort(all(G[i]), [&](const int &a, const int &b) {
            return order[a] < order[b];
        });
    }

    queue<int> Q;
    vector<int> ret;
    V[0] = true;
    Q.push(0);

    while (!Q.empty()) {
        int c = Q.front();
        Q.pop();
        ret.push_back(c);

        for (int n : G[c]) {
            if (V[n]) continue;
            V[n] = true;
            Q.push(n);
        }
    }

    if (ret == ans) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
