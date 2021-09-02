//
// Created by 신승민 on 2021/09/01.
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

vi qnqo(const vi &A) {
    vi ret;

    vi psum(A.size() + 1);
    psum[0] = 0;
    // 이렇게 하면, [i..j] 범위의 합을 P[j+1]-P[i]로 구할 수 있음.
    for (int i = 1; i < A.size() + 1; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }
    for (int i = 0; i < A.size(); i++) {
        for (int j = i; j < A.size(); j++) {
            ret.push_back(psum[j + 1] - psum[i]);
        }
    }
    sort(all(ret));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    int N, M;
    cin >> N;
    vi A(N);
    RP(i, N) cin >> A[i];
    cin >> M;
    vi B(M);
    RP(i, M) cin >> B[i];
    vi a = qnqo(A), b = qnqo(B);

    int i = 0;
    ll ans = 0;
    while (i < a.size()) {
        int upindex = upper_bound(all(a), a[i]) - a.begin();
        ll acount = upindex - i; // a[i]의 갯수를 구한다.

        ll bcount = upper_bound(all(b), T - a[i]) - lower_bound(all(b), T - a[i]); // 이에 해당하는 b의 총 갯수를 구한다.
        ans += acount * bcount; // a와 b 각각이 하나의 가능한 케이스를 의미하므로, 각자 크로스한다,.

        i = upindex;
    }
    cout << ans << endl;

    return 0;
}
