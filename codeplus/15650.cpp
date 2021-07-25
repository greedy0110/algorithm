//
// Created by 신승민 on 2021/07/25.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int N, M;
vector<int> C(10, 0);

void go(int idx, int cnt) {
    if (cnt == M) {
        RP(i, N + 1) if (C[i]) cout << i << " ";
        cout << endl;
        return;
    }

    if (idx == N + 1) return;

    C[idx] = 1;
    go(idx + 1, cnt + 1);
    C[idx] = 0;
    go(idx + 1, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    go(1, 0);

    return 0;
}
