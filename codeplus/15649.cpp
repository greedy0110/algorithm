//
// Created by 신승민 on 2021/07/25.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

vector<int> C(10, 0);
vector<int> A(10);
int N, M;

void go(int index) {
    if (index == M) {
        RP(i, M) cout << A[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (C[i] == 1) continue;
        C[i] = 1;
        A[index] = i;
        go(index + 1);
        C[i] = 0;
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
