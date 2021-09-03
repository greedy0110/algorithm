//
// Created by 신승민 on 2021/09/03.
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

string trans(map<char, int> &index, const string &a, const string &w, int x) {
    assert(0 <= x && x < a.size());
    string ans;
    for (int i = 0; i < w.size(); i++) {
        ans.push_back(a[(index[w[i]] + x) % a.size()]);
    }
    return ans;
}

vi find_fail(const string &p) {
    int m = p.size();
    vi fail(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = fail[j - 1];
        if (p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

bool only_one(const string &s, const string &p) {
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
            } else j++;
        }
    }
    return cnt == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string A, W, S;
        cin >> A >> W >> S;
        map<char, int> index;
        for (int i = 0; i < A.size(); i++) {
            index[A[i]] = i;
        }

        vi ans;
        for (int x = 0; x < A.size(); x++) {
            auto could = trans(index, A, W, x);
            if (only_one(S, could)) ans.push_back(x);
        }
        if (ans.empty()) cout << "no solution" << endl;
        else {
            if (ans.size() == 1) cout << "unique: ";
            else cout << "ambiguous: ";
            for (int a : ans) cout << a << " ";
            cout << endl;
        }
    }

    return 0;
}
