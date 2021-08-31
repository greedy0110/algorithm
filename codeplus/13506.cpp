//
// Created by 신승민 on 2021/08/31.
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

vi find_fail(const string &p) {
    int m = p.size();
    // i 번째 문자 까지 왔을 때, suffix prefix 가 같은 문자열의 최대 길이.
    vi fail(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = fail[j - 1];
        if (p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    auto fail = find_fail(s);
    vi cnt(s.size() + 1, 0);
    for (int i = 0; i < (int) s.size() - 1; i++) {
        cnt[fail[i]]++;
    }

    for (int i = fail.back(); i != 0; i = fail[i-1]) {
        if (cnt[i] >= 1) {
            cout << s.substr(0, i) << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
