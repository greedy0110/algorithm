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

struct Point {
    double x, y, z;
};

double dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

Point make(Point a, Point b, double m) {
    // m == 0 -> a
    // m == 1 -> b
    Point ret;
    ret.x = a.x * (1 - m) + b.x * m;
    ret.y = a.y * (1 - m) + b.y * m;
    ret.z = a.z * (1 - m) + b.z * m;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Point A, B, C;
    cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z;
    double left = 0.0;
    double right = 1.0;

    while (abs(left - right) > 1e-8) {
        double m1 = left + (right - left) / 3, m2 = right - (right - left) / 3;
        Point p1 = make(A, B, m1), p2 = make(A, B, m2);
        double d1 = dist(C, p1), d2 = dist(C, p2);
        if (d1 > d2) {
            left = m1;
        } else {
            right = m2;
        }
    }

    cout << setprecision(10) << fixed << sqrt(dist(make(A, B, left), C)) << endl;

    return 0;
}
