//
// Created by 신승민 on 2021/07/29.
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

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    RP(_, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int a = 0; a < N; a++) {
        for (int b : G[a]) {
            if (a == b) continue;
            for (int c : G[b]) {
                if (a == c || b == c) continue;
                for (int d : G[c]) {
                    if (a == d || b == d || c == d) continue;
                    for (int e : G[d]) {
                        if (a == e || b == e || c == e || d == e) continue;
                        cout << 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
