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
    auto fail = find_fail(s);
    vi cnt(s.size() + 1, 0);
    cnt[s.size()] = 1;
    for (int i = 0; i < s.size(); i++) {
        // len 인 것이 몇 개 나왔나?
        cnt[fail[i]]++;
    }

    // 작은 건, 큰 것에서 이미 반복해서 나왔을 것이다. 가산할 수있다.



    for (int i = s.size(); i != 0; i = fail[i - 1]) {
        cout << i << " " << cnt[i] << endl;
    }

    return 0;
}
