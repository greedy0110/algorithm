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

int kmp(const string &s, const string &p) {
    int n = s.size();
    int m = p.size();
    vi fail = find_fail(p);
    int cnt = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) j = fail[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                cnt++;
                j = fail[j];
            } else {
                j++;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string A, B;
    cin >> A >> B;
    string S = B + B;
    S.pop_back(); // 마지막 문자는 예외

    cout << kmp(S, A) << endl;

    return 0;
}
