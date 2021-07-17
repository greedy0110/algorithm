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

    stack<int> ids;
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if (ch == '(') {
            ids.push(i);
        } else {
            int p = ids.top();
            ids.pop();
            if (i - p == 1) {
                ans += ids.size();
            } else {
                ans += 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
