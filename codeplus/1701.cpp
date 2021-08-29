//
// Created by 신승민 on 2021/08/29.
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

vi find_fail(string p) {
    // fail 함수에 등장했다는 말은, 해당 문자열이 최소 2번은 나온 것이라는 말!
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

    int ans = -1;
    for (int i = 0; i < s.size(); i++) {
        string p = s.substr(i, s.size() - i);
        auto fail = find_fail(p);
        ans = max(ans, *max_element(all(fail)));
    }
    cout << ans << endl;

    return 0;
}
