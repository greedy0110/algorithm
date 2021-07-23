//
// Created by 신승민 on 2021/07/23.
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

    int E, S, M;
    cin >> E >> S >> M;
    for (int x = 0; x < 8000; x++) {
        if (x % 15 == E-1 && x % 28 == S-1 && x % 19 == M-1) {
            cout << x + 1 << endl;
            return 0;
        }
    }

    return 0;
}
