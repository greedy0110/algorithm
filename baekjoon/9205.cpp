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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> pos(n + 2);
        RP (i, n + 2) {
            int a, b;
            cin >> a >> b;
            pos[i] = {a, b};
        }

        vector<vector<bool>> reach(n + 2, vb(n + 2, false));

        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < n + 2; j++) {
                int dist = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
                reach[i][j] = dist <= 1000;
            }
        }

        for (int k = 0; k < n + 2; k++) {
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < n + 2; j++) {
                    reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
                }
            }
        }

        cout << (reach[0][n + 1] ? "happy" : "sad") << endl;
    }

    return 0;
}
