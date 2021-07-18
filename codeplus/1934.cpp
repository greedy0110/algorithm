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

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int gcd = a, temp = b;
        while (temp != 0) {
            int r = gcd % temp;
            gcd = temp;
            temp = r;
        }
        cout << a * b / gcd << endl;
    }
    return 0;
}
