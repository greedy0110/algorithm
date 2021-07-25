//
// Created by 신승민 on 2021/07/25.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int N, M;
int A[10];

void go(int idx) {
    if (idx == M) {
        RP(i, M) cout << A[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= N; i++) {
        A[idx] = i;
        go(idx + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    go(0);

    return 0;
}
