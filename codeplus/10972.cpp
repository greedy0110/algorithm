//
// Created by 신승민 on 2021/07/26.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

bool nt_pr(vector<int> &cur) {
    int i = cur.size() - 2;
    while (i >= 0 && cur[i] >= cur[i + 1]) i--;
    if (i < 0) return false;

    int j = cur.size() - 1;
    while (cur[i] >= cur[j]) j--;
    swap(cur[i], cur[j]);

    reverse(cur.begin() + i + 1, cur.end());
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> cur(N);
    RP(i, N) cin >> cur[i];


    if (nt_pr(cur)) {
        RP(i, N) cout << cur[i] << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
