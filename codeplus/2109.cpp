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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vvi P(10000);
    RP(_, N) {
        int p, d;
        cin >> p >> d;
        d--;
        P[d].push_back(p);
    }

    RP(i, 10000) {
        sort(all(P[i]), [&](int a, int b) {
            return a > b;
        });
    }

    int ans = 0;
    for (int now = 0; now < 10000; now++) {
        int temp = 0;
        if (!P[now].empty()) temp = P[now][0];
        for (int i = 1; now + i < 10000; i++) {
            if (P[now + i].size() <= i) continue;
            temp = max(temp, P[now + i][i]);
        }
        ans += temp;
    }

    cout << ans << endl;

    return 0;
}
