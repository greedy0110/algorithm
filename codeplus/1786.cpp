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
    int m = p.size();
    vi fail(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        // i와 j가 같지 않을 때, 다음 비교는 fail[j] 부터 하자.
        while (j > 0 && p[i] != p[j]) j = fail[j - 1];
        if (p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

vi kmp(string s, string p) {
    int n = s.size();
    int m = p.size();

    vi fail = find_fail(p);
    vi ret;

    for (int i = 0, j = 0; i < n; i++) {
        // 현재 글자가 불일치 하면, fail 값을 계속 따라감.
        while (j > 0 && s[i] != p[j]) j = fail[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ret.push_back(i - m + 1);
                j = fail[j]; // j 에서 찾지 못한 것 처럼 이동.
            } else {
                j++;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, p;
    getline(cin, s);
    getline(cin, p);

    auto ret = kmp(s, p);
    cout << ret.size() << endl;
    for (int i : ret) {
        cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}
