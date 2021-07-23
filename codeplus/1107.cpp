//
// Created by 신승민 on 2021/07/23.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

const int NONE = 1000000;
int N, M;
vector<bool> broken(10, false);

int possible(int c) {
    if (c == 0) {
        if (broken[0]) return NONE;
        else return N + 1;
    }

    int len = abs(N-c);
    while (c > 0) {
        if (broken[c % 10]) return NONE;
        len++;
        c /= 10;
    }

    return len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    RP(i, M) {
        int temp;
        cin >> temp;
        broken[temp] = true;
    }

    int ans = abs(N - 100);
    for (int c = 0; c <= 1000000; c++) {
        ans = min(ans, possible(c));
    }
    cout << ans << endl;

    return 0;
}
