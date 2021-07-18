//
// Created by 신승민 on 2021/07/18.
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

    vector<int> primes;
    vector<int> checks(1000001, true);
    checks[0] = checks[1] = false;

    for (int i = 2; i <= 1000001; i++) {
        if (!checks[i]) continue;
        primes.push_back(i);
        for (int j = i * 2; j <= 1000001; j += i) {
            checks[j] = false;
        }
    }

    int n;
    cin >> n;
    while (n != 0) {
        int a, b = -1;
        for (int i = 1; i < primes.size(); i++) {
            a = primes[i];
            if (checks[n - a]) {
                b = n - a;
                break;
            }
        }
        if (b != -1) cout << n << " = " << a << " + " << b << endl;
        else cout << "Goldbach's conjecture is wrong." << endl;

        cin >> n;
    }

    return 0;
}
