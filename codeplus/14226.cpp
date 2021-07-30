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

    int MAX_SIZE = 2000;
    int S;
    cin >> S;

    vector<vector<int>> D(MAX_SIZE + 1, vector<int>(MAX_SIZE + 1, -1));

    queue<pair<int, int>> q;
    D[1][0] = 0;
    q.push({1, 0});

    while (!q.empty()) {
        int cs = q.front().first;
        int cc = q.front().second;
        int dist = D[cs][cc];
        q.pop();

        if (D[cs][cs] == -1) {
            D[cs][cs] = dist + 1;
            q.push({cs, cs});
        }
        if (cs + cc <= MAX_SIZE && D[cs + cc][cc] == -1) {
            D[cs + cc][cc] = dist + 1;
            q.push({cs + cc, cc});
        }
        if (cs - 1 >= 0 && D[cs - 1][cc] == -1) {
            D[cs - 1][cc] = dist + 1;
            q.push({cs - 1, cc});
        }
    }

    int ans = 1000;
    for (int c = 0; c <= MAX_SIZE; c++) {
        if (D[S][c] == -1) continue;
        ans = min(ans, D[S][c]);
    }
    cout << ans << endl;

    return 0;
}
