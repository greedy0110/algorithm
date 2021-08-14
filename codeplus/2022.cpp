//
// Created by 신승민 on 2021/08/15.
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

double X, Y, C;

double calc(double d) {
    double h1 = sqrt(X * X - d * d), h2 = sqrt(Y * Y - d * d);
    return (h1 * h2) / (h1 + h2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> X >> Y >> C;
    double left = 0, right = min(X, Y);

    while (abs(left - right) > 1e-6) {
        double mid = (left + right) / 2;
        if (calc(mid) >= C) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout.precision(3);
    cout << fixed << left << endl;

    return 0;
}
