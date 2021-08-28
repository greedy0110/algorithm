//
// Created by 신승민 on 2021/08/28.
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

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    vi D(f + 1, -1);

    queue<int> q;
    D[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int c = q.front();
        int cd = D[c];
        q.pop();

        int un = c + u, dn = c - d;
        if (un <= f && D[un] == -1) {
            D[un] = cd + 1;
            q.push(un);
        }

        if (dn >= 1 && D[dn] == -1) {
            D[dn] = cd + 1;
            q.push(dn);
        }
    }

    if (D[g] != -1) cout << D[g] << endl;
    else cout << "use the stairs" << endl;

    return 0;
}
