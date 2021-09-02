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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vb s(20, false);
    int M;
    cin >> M;
    RP(_, M) {
        string cmd;
        cin >> cmd;
        int param;
        if (cmd == "add") {
            cin >> param;
            s[param - 1] = true;
        } else if (cmd == "remove") {
            cin >> param;
            s[param - 1] = false;
        } else if (cmd == "check") {
            cin >> param;
            cout << (s[param - 1] ? 1 : 0) << endl;
        } else if (cmd == "toggle") {
            cin >> param;
            s[param - 1] = !s[param - 1];
        } else if (cmd == "all") {
            RP(i, 20) s[i] = true;
        } else {
            RP(i, 20) s[i] = false;
        }
    }

    return 0;
}
