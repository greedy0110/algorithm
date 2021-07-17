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

    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        stack<char> S;
        string temp;

        getline(cin, temp);
        temp += '\n';

        for (char ch: temp) {
            if (ch == ' ' || ch == '\n') {
                while (!S.empty()) {
                    cout << S.top();
                    S.pop();
                }
                cout << ch;
            } else S.push(ch);
        }
    }

    return 0;
}
