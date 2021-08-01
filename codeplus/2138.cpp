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

int go(vi A, const vi &B, int cnt) {
    int N = A.size();

    for (int i = 1; i < N; i++) {
        if (A[i - 1] != B[i - 1]) {
            cnt++;
            for (int j = 0; j < 3; j++) {
                int ni = i + j - 1;
                if (ni >= N) continue;
                A[ni] = 1 - A[ni];
            }
        }
        assert(A[i - 1] == B[i - 1]);
    }

    if (A[N - 1] == B[N - 1]) return cnt;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vi A(N), B(N);
    string temp;
    cin >> temp;
    RP(i, N) A[i] = temp[i] - '0';
    cin >> temp;
    RP(i, N) B[i] = temp[i] - '0';

    int ret1 = go(A, B, 0);

    A[0] = 1 - A[0];
    A[1] = 1 - A[1];
    int ret2 = go(A, B, 1);

    if (ret1 == -1 && ret2 == -1) cout << -1 << endl;
    else if (ret1 == -1) cout << ret2 << endl;
    else if (ret2 == -1) cout << ret1 << endl;
    else cout << min(ret1, ret2) << endl;

    return 0;
}
