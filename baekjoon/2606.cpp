//
// Created by 신승민 on 2021/08/01.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vvi G(N);
    RP(_, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    vb V(N, false);
    V[0] = true;
    queue<int> q;
    q.push(0);

    int cnt = -1;
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        cnt++;

        for (int n : G[c]) {
            if (V[n]) continue;
            V[n] = true;
            q.push(n);
        }
    }

    cout << cnt << endl;

    return 0;
}
