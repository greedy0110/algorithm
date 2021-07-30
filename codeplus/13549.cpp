//
// Created by 신승민 on 2021/07/30.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int MAX_SIZE = 100000;
    int N, K;
    cin >> N >> K;
    if (N == K) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> D(MAX_SIZE + 1, -1);
    deque<int> dq;

    D[N] = 0;
    dq.push_back(N);

    while (!dq.empty()) {
        int c = dq.front();
        int dist = D[c];
        dq.pop_front();

        if (c * 2 <= MAX_SIZE && D[c * 2] == -1) {
            D[c * 2] = dist;
            dq.push_front(c * 2);
        }
        if (c + 1 <= MAX_SIZE && D[c + 1] == -1) {
            D[c + 1] = dist + 1;
            dq.push_back(c + 1);
        }
        if (c - 1 >= 0 && D[c - 1] == -1) {
            D[c - 1] = dist + 1;
            dq.push_back(c - 1);
        }
    }

    cout << D[K] << endl;

    return 0;
}
