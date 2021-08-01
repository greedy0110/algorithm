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

struct Stone {
    int a;
    int b;
    int c;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;
    vector<vb> V(A + B + C + 1, vb(A + B + C + 1, false));
    queue<Stone> q;
    V[A][B] = true;
    q.push({A, B, C});

    while (!q.empty()) {
        int ca = q.front().a;
        int cb = q.front().b;
        int cc = q.front().c;
        q.pop();

        if (ca == cb && cb == cc) {
            cout << 1 << endl;
            return 0;
        }
        int nxt[] = {ca, cb, cc};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (nxt[i] > nxt[j]) {
                    int temp[] = {ca, cb, cc};
                    temp[i] -= nxt[j];
                    temp[j] += nxt[j];
                    if (V[temp[0]][temp[1]]) continue;
                    V[temp[0]][temp[1]] = true;
                    q.push({temp[0], temp[1], temp[2]});
                }
            }
        }
    }

    cout << 0 << endl;

    return 0;
}
