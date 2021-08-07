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

    ll S, T;
    cin >> S >> T;

    if (S == T) {
        cout << 0 << endl;
        return 0;
    }

    map<ll, string> discovered;
    queue<ll> q;
    discovered[S] = "";
    q.push(S);

    while (!q.empty()) {
        ll c = q.front();
        string history = discovered[c];
        q.pop();

        if (c == T) {
            cout << history << endl;
            return 0;
        }

        ll n = c * c;
        char op = '*';
        if (n <= T && discovered.find(n) == discovered.end()) {
            discovered[n] = history + op;
            q.push(n);
        }

        n = c + c;
        op = '+';
        if (n <= T && discovered.find(n) == discovered.end()) {
            discovered[n] = history + op;
            q.push(n);
        }

        n = c - c;
        op = '-';
        if (discovered.find(n) == discovered.end()) {
            discovered[n] = history + op;
            q.push(n);
        }

        if (c == 0) continue;
        n = c / c;
        op = '/';
        if (discovered.find(n) == discovered.end()) {
            discovered[n] = history + op;
            q.push(n);
        }
    }

    cout << -1 << endl;
    return 0;
}
