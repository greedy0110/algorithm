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

    string str;
    getline(cin, str);
    str += '\n';
    stack<char> s;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if (ch == ' ' || ch == '\n') {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
            cout << ch;
        } else if (ch == '<') {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }

            while (str[i] != '>') {
                cout << str[i++];
            }
            cout << str[i];
        } else {
            s.push(ch);
        }
    }

    return 0;
}
