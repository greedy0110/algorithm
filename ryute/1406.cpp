//
// Created by 신승민 on 2021/07/12.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string init;
    char cmd, temp;
    cin >> init;

    int M;
    cin >> M;

    list<char> editor(init.begin(), init.end());
    list<char>::iterator cursor = editor.end(), left;

    for (int i = 0; i < M; i++) {
        cin >> cmd;
        switch (cmd) {
            case 'L':
                if (editor.begin() == cursor) break;
                cursor--;
                break;
            case 'D':
                if (editor.end() == cursor) break;
                cursor++;
                break;
            case 'B':
                if (editor.begin() == cursor) break;
                left = cursor;
                left--;
                editor.erase(left);
                break;
            case 'P':
                cin >> temp;
                editor.insert(cursor, temp);
                break;
        }
    }

    for (auto it = editor.begin(); it != editor.end(); it++) {
        cout << *it;
    }
    cout << endl;

    return 0;
}
