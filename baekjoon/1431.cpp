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

    int N;
    cin >> N;
    vector<string> S(N);
    RP(i, N) cin >> S[i];
    sort(all(S), [&](const string &a, const string &b) {
        if (a.size() != b.size()) {
            return a.size() < b.size();
        }
        assert(a.size() == b.size());

        int as = 0, bs = 0;
        for (int i = 0; i < a.size(); i++) {
            if (isdigit(a[i])) as += a[i] - '0';
            if (isdigit(b[i])) bs += b[i] - '0';
        }

        if (as != bs) {
            return as < bs;
        }

        return a < b;
    });

    RP(i, N) cout << S[i] << endl;

    return 0;
}
