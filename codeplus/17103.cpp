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

    int N = 1000000;
    vector<int> ps;
    vector<bool> ck(N + 1, true);
    ck[0] = false;
    ck[1] = false;
    for (int i = 2; i <= N; i++) {
        if (!ck[i]) continue;
        ps.push_back(i);
        for (int j = i * 2; j <= N; j += i) {
            ck[j] = false;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;

        int cnt = 0;
        for (int a : ps) {
            int b = num - a;
            if (a > b) break;
            if (ck[b]) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
