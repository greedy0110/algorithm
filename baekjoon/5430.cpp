//
// Created by 신승민 on 2021/09/02.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'
#define custom_pq(X) priority_queue<X, vector<X>, X>

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

deque<int> to_output(string &input) {
    // [] 버리기
    input = input.substr(1, input.size() - 2);
    // 편의룰 위해 마지막에 , 추가하기
    input.push_back(',');
    deque<int> ret;
    int start = 0;
    for (int i = 1; i < input.size(); i++) {
        if (input[i] == ',') {
            // [start, i) 범위가 숫자.
            ret.push_back(stoi(input.substr(start, i - start)));
            start = i + 1;
        }
    }
    return ret;
}

string to_form(deque<int> q, bool reverse) {
    string form;
    if (reverse) {
        for (auto it = q.rbegin(); it != q.rend(); it++) {
            form += to_string(*it) + ',';
        }
    } else {
        for (auto it = q.begin(); it != q.end(); it++) {
            form += to_string(*it) + ',';
        }
    }
    if (!form.empty()) form.pop_back();
    return '[' + form + ']';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string cmd, input;
        int N;
        cin >> cmd >> N >> input;
        auto q = to_output(input);
        assert(q.size() == N);
        bool reverse = false;
        bool error = false;
        for (char c : cmd) {
            if (c == 'R') {
                reverse = !reverse;
            } else if (c == 'D') {
                if (q.empty()) {
                    error = true;
                    break;
                }

                if (reverse) q.pop_back();
                else q.pop_front();
            } else { assert(false); }
        }

        if (error) cout << "error" << endl;
        else cout << to_form(q, reverse) << endl;
    }

    return 0;
}
