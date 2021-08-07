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

    vb is_prime(10000, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i < 10000; i++) {
        if (!is_prime[i]) continue;
        is_prime[i] = true;
        for (int j = i * 2; j < 10000; j += i) {
            is_prime[j] = false;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int S, E;
        cin >> S >> E;

        vi D(10000, -1);
        queue<int> q;
        q.push(S);
        D[S] = 0;

        while (!q.empty()) {
            int c = q.front();
            int dist = D[c];
            q.pop();

            for (int i = 0; i < 4; i++) {
                for (int num = 0; num < 10; num++) {
                    string cnums = to_string(c);
                    if (i == 0 && num == 0) continue;
                    cnums[i] = num + '0';
                    int n = stoi(cnums);
                    if (D[n] != -1) continue;
                    if (!is_prime[n]) continue;
                    D[n] = dist + 1;
                    q.push(n);
                }
            }
        }
        cout << D[E] << endl;
    }


    return 0;
}
