//
// Created by 신승민 on 2021/08/03.
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

    string N;
    cin >> N;
    vi ds;
    int dsum = 0;
    for (char l : N) {
        int c = l - '0';
        ds.push_back(c);
        dsum += c;
    }

    sort(all(ds), [](int a, int b) { return a > b; });
    if (dsum % 3 != 0 || ds.back() != 0) {
        cout << -1 << endl;
    } else {
        for (int p : ds) {
            cout << p;
        }
        cout << endl;
    }

    return 0;
}
