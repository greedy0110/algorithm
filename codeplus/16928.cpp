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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vi D(101, -1);
    vi next(101, -1);
    RP(i, 101) next[i] = i;
    RP(i, N) {
        int a, b;
        cin >> a >> b;
        next[a] = b;
    }
    RP(i, M) {
        int a, b;
        cin >> a >> b;
        next[a] = b;
    }

    queue<int> q;
    D[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int n = c + i;

            if (n > 100) continue;
            n = next[n];
            if (D[n] != -1) continue;

            D[n] = D[c] + 1;
            q.push(n);
        }
    }

    cout << D[100] << endl;

    return 0;
}
