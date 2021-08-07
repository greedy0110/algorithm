//
// Created by 신승민 on 2021/08/07.
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    for (int a = 0; a < N; a++) {
        int b = N - a;
        if (a * b < K) continue;

        int k = K;
        int a1 = 0, a2 = 0, b1 = b, b2 = 0;
        while (k != 0) {
            if (k >= b) {
                a1++;
                k -= b;
            } else {
                a2++;
                b1 = b - k;
                b2 = k;
                k = 0;
            }
        }
        if (a1 + a2 != a) continue;
        for (int i = 0; i < a1; i++) {
            cout << "A";
        }
        for (int i = 0; i < b1; i++) {
            cout << "B";
        }
        for (int i = 0; i < a2; i++) {
            cout << "A";
        }
        for (int i = 0; i < b2; i++) {
            cout << "B";
        }
        return 0;
    }

    cout << -1 << endl;
    return 0;
}
