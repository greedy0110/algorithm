//
// Created by 신승민 on 2021/08/01.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> pts;
    stack<int> s;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            s.push(i);
        } else if (str[i] == ')') {
            pts.emplace_back(s.top(), i);
            s.pop();
        }
    }

    vector<string> ans;
    int ptssize = pts.size();
    for (int i = 1; i < (1 << ptssize); i++) {
        vb skip(str.size(), false);
        for (int j = 0; j < ptssize; j++) {
            if (i & (1 << j)) {
                skip[pts[j].first] = true;
                skip[pts[j].second] = true;
            }
        }

        string cur;
        for (int j = 0; j < str.size(); j++) {
            if (skip[j]) continue;
            cur += str[j];
        }
        ans.push_back(cur);
    }

    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    for (auto &a:ans) {
        cout << a << endl;
    }

    return 0;
}
