//
// Created by 신승민 on 2021/04/04.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;

vi cache = vi(1001);
vi p = vi(1001);
int N;

int mp(int n) {
    if (n == 0) return 0;

    int &ans = cache[n];
    if (ans != -1) return ans;

    int ret = -1;

    for (int i = 1; i <= n; i++) {
        ret = max(ret, p[i] + mp(n - i));
    }

    return ans = ret;
}

int main() {
    fill(cache.begin(), cache.end(), -1);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> p[i];

    cout << mp(N) << endl;

    return 0;
}