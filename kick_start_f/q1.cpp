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

int n;
string street;

bool in_street(int x) {
    return 0 <= x && x < n;
}

int dx[] = {1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        cin >> street;

        queue<int> q;
        vi dist(n, -1);
        for (int i = 0; i < n; i++) {
            if (street[i] == '1') {
                dist[i] = 0;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int cd = dist[cur];

            for (int i = 0; i < 2; i++) {
                int nx = cur + dx[i];
                if (in_street(nx)) {
                    if (dist[nx] != -1) continue;
                    dist[nx] = cd + 1;
                    q.push(nx);
                }
            }
        }

        ll ans = 0;
        for (int d : dist) {
            if (d == -1) continue;
            ans = ans + (ll) d;
        }
        cout << "Case #" << t << ": ";
        cout << ans << endl;
    }

    return 0;
}
