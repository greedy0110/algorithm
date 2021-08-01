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

struct History {
    char cmd;
    int prev;
};

void print(const vector<History> &hs, int n) {
    if (hs[n].prev != -1) {
        print(hs, hs[n].prev);
        cout << hs[n].cmd;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int MX = 10000;

    int T;
    cin >> T;
    while (T--) {
        vector<History> hs(MX);
        vi D(MX, -1);
        int A, B;
        cin >> A >> B;

        queue<int> q;
        hs[A] = {'X', -1};
        D[A] = 0;
        q.push(A);

        while (!q.empty()) {
            int c = q.front();
            int dist = D[c];
            q.pop();

            if (c == B) break;

            int nd = (2 * c) % MX;
            if (D[nd] == -1) {
                D[nd] = dist + 1;
                hs[nd] = {'D', c};
                q.push(nd);
            }

            int ns = 9999;
            if (c != 0) ns = c - 1;
            if (D[ns] == -1) {
                D[ns] = dist + 1;
                hs[ns] = {'S', c};
                q.push(ns);
            }

            vi d(4);
            int temp = c;
            for (int i = 0; i < 4; i++) {
                d[3 - i] = temp % 10;
                temp /= 10;
            }

            int nl = 1000 * d[1] + 100 * d[2] + 10 * d[3] + d[0];
            if (D[nl] == -1) {
                D[nl] = dist + 1;
                hs[nl] = {'L', c};
                q.push(nl);
            }

            int nr = 1000 * d[3] + 100 * d[0] + 10 * d[1] + d[2];
            if (D[nr] == -1) {
                D[nr] = dist + 1;
                hs[nr] = {'R', c};
                q.push(nr);
            }
        }

        print(hs, B);
        cout << endl;
    }


    return 0;
}
