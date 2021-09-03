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

vi find_fail(const vi &p) {
    int m = p.size();
    vi fail(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = fail[j - 1];
        if (p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

// fail 함수 재활용하자.
bool kmp(const vi &s, const vi &p, const vi &fail) {
    int n = s.size();
    int m = p.size();
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) j = fail[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                return true;
            } else j++;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vvi P(N);
    RP(i, N) {
        int m;
        cin >> m;
        P[i] = vi(m);
        RP(j, m) cin >> P[i][j];
    }

    if (P[0].size() < K) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < P[0].size() - K + 1; i++) {
        // P[i..i+K-1] 이번에 검사하고싶은 패턴.
        vi p1(K), p2(K);
        for (int j = 0; j < K; j++) {
            p1[j] = P[0][i + j];
            p2[j] = P[0][i + K - 1 - j];
        }

        vi f1 = find_fail(p1);
        vi f2 = find_fail(p2);

        bool ok = true;
        for (int j = 1; j < N; j++) {
            if (kmp(P[j], p1, f1) || kmp(P[j], p2, f2)) continue;
            ok = false;
        }
        if (ok) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
