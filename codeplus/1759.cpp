//
// Created by 신승민 on 2021/07/25.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int L, C;
char given[16];
vector<bool> V(16, false);

void check() {
    int ja = 0, mo = 0;

    for (int i = 0; i < C; i++) {
        if (V[i]) {
            char c = given[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') mo++;
            else ja++;
        }
    }

    if (mo >= 1 && ja >= 2) {
        for (int i = 0; i < C; i++) {
            if (V[i]) cout << given[i];
        }
        cout << endl;
    }
}

void go(int idx, int cnt) {
    if (cnt == L) {
        check();
        return;
    }

    if (idx == C) return;

    V[idx] = true;
    go(idx + 1, cnt + 1);
    V[idx] = false;
    go(idx + 1, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> L >> C;
    RP(i, C) cin >> given[i];

    sort(given, given + C);

    go(0, 0);

    return 0;
}
