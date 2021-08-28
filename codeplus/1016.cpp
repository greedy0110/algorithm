//
// Created by 신승민 on 2021/08/24.
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

// check[i] = min+i 가 지워지면 true
bool check[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll min, max;
    cin >> min >> max;

    for (ll i = 2; i * i <= max; i++) {
        // min 보다 크면서, i^2의 배수를 찾는 것.
        ll start = i * i - min % (i * i);
        if (start == i * i) {
            start = 0;
        }

        for (ll j = start; j <= max - min; j += i * i) {
            check[j] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i<=max-min; i++) {
        if (!check[i]) ans++;
    }
    cout << ans << endl;

    return 0;
}
