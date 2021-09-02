//
// Created by 신승민 on 2021/09/01.
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    set<string> roll;
    int N;
    cin >> N;
    string name, cmd;
    RP(_, N) {
        cin >> name >> cmd;
        if (cmd == "enter") {
            roll.insert(name);
        } else {
            roll.erase(name);
        }
    }

    for (auto it = roll.rbegin(); it != roll.rend(); it++) {
        cout << *it << endl;
    }

    return 0;
}
