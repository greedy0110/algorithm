//
// Created by 신승민 on 2021/07/12.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, temp;
    string cmd;
    deque<int> d;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> temp;
            d.push_front(temp);
        } else if (cmd == "push_back") {
            cin >> temp;
            d.push_back(temp);
        } else if (cmd == "pop_front") {
            if (d.empty()) {
                cout << -1 << endl;
                continue;
            }
            cout << d.front() << endl;
            d.pop_front();
        } else if (cmd == "pop_back") {
            if (d.empty()) {
                cout << -1 << endl;
                continue;
            }
            cout << d.back() << endl;
            d.pop_back();
        } else if (cmd == "size") {
            cout << d.size() << endl;
        } else if (cmd == "empty") {
            cout << (d.empty() ? 1: 0) << endl;
        } else if (cmd == "front") {
            if (d.empty()) {
                cout << -1 << endl;
                continue;
            }
            cout << d.front() << endl;
        } else if (cmd == "back") {
            if (d.empty()) {
                cout << -1 << endl;
                continue;
            }
            cout << d.back() << endl;
        }
    }

    return 0;
}
