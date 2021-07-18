//
// Created by 신승민 on 2021/07/18.
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

    string ot;
    cin >> ot;

    if (ot == "0") {
        cout << 0 << endl;
        return 0;
    }

    int N = ot.size();

    vector<int> result(N * 3);

    for (int i = 0; i < N; i++) {
        int num = ot[i] - '0';

        result[3 * i] = num >= 4 ? 1 : 0;
        result[3 * i + 2] = num % 2;
        result[3 * i + 1] = (num - (result[3 * i + 2] + 4 * result[3 * i])) / 2;
    }

    bool flag = true;
    for (int i=0; i<N*3; i++) {
        if (flag && result[i] == 0) continue;
        flag = false;
        cout << result[i];
    }
    cout << endl;

    return 0;
}
