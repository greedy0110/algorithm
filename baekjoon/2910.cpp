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

struct Type {
    int cnt;
    int order;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, C;
    cin >> N >> C;
    vi A(N);
    map<int, Type> m;
    RP(i, N) {
        cin >> A[i];

        if (m.find(A[i]) == m.end()) {
            m[A[i]] = {0, i};
        }
        m[A[i]].cnt++;
    }

    sort(all(A), [&](int a, int b) {
        auto &at = m[a];
        auto &bt = m[b];

        if (at.cnt != bt.cnt) {
            return at.cnt > bt.cnt;
        }

        return at.order < bt.order;
    });

    RP(i, N) cout << A[i] << " ";
    cout << endl;

    return 0;
}
