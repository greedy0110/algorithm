//
// Created by 신승민 on 2021/08/07.
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

    string S, T;
    cin >> S >> T;

    while (S.size() != T.size()) {
        if (T.back() == 'A') {
            T.pop_back();
        } else {
            T.pop_back();
            reverse(all(T));
        }
    }
    if (S == T) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}
