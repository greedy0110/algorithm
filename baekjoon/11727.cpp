#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;

vlli cache = vlli(1001);

lli count(int n) {
    if (n == 1) return 1;
    if (n == 2) return 3;

    lli &ans = cache[n];

    if (ans != -1) return ans;

    return ans = (count(n - 1) + 2 * count(n - 2)) % 10007;
}

int main() {
    fill(cache.begin(), cache.end(), -1);

    int n;
    cin >> n;

    cout << count(n) << endl;

    return 0;
}