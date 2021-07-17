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

    stack<char> left, right;
    string temp;
    cin >> temp;
    for (char ch : temp) {
        left.push(ch);
    }

    int M;
    cin >> M;
    while (M--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (left.empty()) continue;
            right.push(left.top());
            left.pop();
        } else if (cmd == 'D') {
            if (right.empty()) continue;
            left.push(right.top());
            right.pop();
        } else if (cmd == 'B') {
            if (left.empty())continue;
            left.pop();
        } else {
            char ch;
            cin >> ch;
            left.push(ch);
        }
    }

    vector<char> lt(left.size() + right.size());
    int lti = left.size() - 1;
    int rti = left.size();
    while (!left.empty()) {
        lt[lti--] = left.top();
        left.pop();
    }
    while (!right.empty()) {
        lt[rti++] = right.top();
        right.pop();
    }
    cout << string(all(lt)) << endl;

    return 0;
}
