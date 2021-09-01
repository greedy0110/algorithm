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
    int n = s.size();
    auto fail = find_fail(s);
    vi cnt(n + 1, 0);

    cnt[n] = 1; // 전체 문자열을 하나 추가하자.
    for (int i = 0; i < n; i++) {
        cnt[fail[i]]++;
    }
    for (int i = n; i > 0; i--) {
        cnt[fail[i - 1]] += cnt[i];
    }
    vector<pair<int, int>> ans;
    for (int i = n; i > 0; i = fail[i - 1])
        ans.push_back({i, cnt[i]});

    reverse(all(ans));
    cout << ans.size() << endl;
    for (auto &a : ans) {
        cout << a.first << " " << a.second << endl;
    }

    return 0;
}
