#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;

vi cache;

vi t;
vi p;
int N;

int mp(int x) {
    if (x > N) return 0;

    int &ans = cache[x];
    if (ans != -1) return ans;

    if (x + t[x] - 1 > N) return ans = mp(x + 1);
    else return ans = max(p[x] + mp(x + t[x]), mp(x + 1));
}

int main() {

    cin >> N;
    cache = vi(N + 1);
    fill(cache.begin(), cache.end(), -1);
    t = vi(N + 1);
    p = vi(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> t[i];
        cin >> p[i];
    }

    cout << mp(1) << endl;

    return 0;
}