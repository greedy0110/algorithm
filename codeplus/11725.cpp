//
// Created by 신승민 on 2021/07/31.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vvi G(N);
    vi P(N, -1);
    RP(_, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<int> q;
    P[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        for (int n : G[c]) {
            if (P[n] != -1) continue;
            P[n] = c;
            q.push(n);
        }
    }

    for (int i = 1; i < N; i++) {
        cout << P[i] + 1 << endl;
    }

    return 0;
}
