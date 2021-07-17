//
// Created by 신승민 on 2021/07/17.
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

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        int cnt = 0;
        bool ans = true;
        for (char ch : str) {
            if (ch == '(') {
                cnt++;
            } else {
                if (cnt == 0) {
                    ans = false;
                    break;
                }
                cnt--;
            }
        }
        if (cnt != 0) ans = false;

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
