//
// Created by 신승민 on 2021/07/18.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int GCD(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int LCM(int a, int b) {
    return a * b / GCD(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a,b; cin >> a >> b;
    cout << GCD(a,b) << endl << LCM(a,b) << endl;

    return 0;
}
