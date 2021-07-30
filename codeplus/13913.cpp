//
// Created by 신승민 on 2021/07/30.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

vector<int> P;
vector<int> D;

void print(int c) {
    if (P[c] != c) {
        print(P[c]);
    }
    cout << c << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int MAX_DIST = 100000;
    int N, K;
    cin >> N >> K;
    P = vector<int>(MAX_DIST + 1);
    D = vector<int>(MAX_DIST + 1, -1);

    if (N == K) {
        cout << 0 << endl;
        cout << N << endl;
        return 0;
    }

    queue<int> q;
    D[N] = 0;
    P[N] = N;
    q.push(N);

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        if (c - 1 >= 0 && D[c - 1] == -1) {
            D[c - 1] = D[c] + 1;
            P[c - 1] = c;
            q.push(c - 1);
        }
        if (c + 1 <= MAX_DIST && D[c + 1] == -1) {
            D[c + 1] = D[c] + 1;
            P[c + 1] = c;
            q.push(c + 1);
        }
        if (2 * c <= MAX_DIST && D[2 * c] == -1) {
            D[2 * c] = D[c] + 1;
            P[2 * c] = c;
            q.push(2 * c);
        }
    }

    cout << D[K] << endl;
    print(K);

    return 0;
}
