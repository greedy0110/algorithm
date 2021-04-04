//
// Created by 신승민 on 2021/04/04.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vlli;

int N, K;
vvi cache = vvi(201, vi(201, -1));

int count(int k, int n) {
    if (k == 1) return 1;

    int &ans = cache[k][n];
    if (ans != -1) return ans;

    int ret = 0;
    for (int i = 0; i <= n; i++) {
        ret += count(k - 1, n - i);
        ret %= 1000000000;
    }

    return ans = ret % 1000000000;
}

int main() {
    cin >> N >> K;

    cout << count(K, N) << endl;

    return 0;
}
