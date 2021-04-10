//
// Created by 신승민 on 2021/04/10.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <queue>
#include <numeric>
#include <set>
#include <map>

using namespace std;

#define all(X) begin((X)), end((X))
#define endl '\n'
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define repeat(i, X) for (int i=0; i<((X)); i++)
#define BIG 987654321
#define SUPER_BIG 987654321123456789

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<string> vs;
typedef priority_queue<int, vi, greater<>> mq;
typedef priority_queue<pii, vpii, greater<>> mpq;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

vi cc = vi(2000001, BIG);
int n, k;

// 5 4 8 16 17
void find_young() {
    mpq q;

    q.push(make_pair(0, n));
    cc[n] = 0;

    int min_d = -1;
    int ways = 0;

    while (!q.empty()) {
        auto value = q.top();
        q.pop();

        int d = value.first;
        int cur = value.second;

        if (min_d != -1 && min_d < d) {
            break;
        }

        if (cur == k) {
            min_d = d;
            ways++;
            continue;
        }

        if (k <= cur) {
            q.push(make_pair(d + cur - k, k));
            continue;
        }
        if (cur == 0) {
            if (cc[1] >= d + 1) {
                cc[1] = d + 1;
                q.push(make_pair(d + 1, 1));
            }
            continue;
        }

        if (cc[cur + 1] >= d + 1) {
            cc[cur + 1] = d + 1;
            q.push(make_pair(d + 1, cur + 1));
        }

        if (cc[cur - 1] >= d + 1) {
            cc[cur - 1] = d + 1;
            q.push(make_pair(d + 1, cur - 1));
        }

        if (cc[2 * cur] >= d + 1) {
            cc[2 * cur] = d + 1;
            q.push(make_pair(d + 1, 2 * cur));
        }
    }

    cout << min_d << endl << ways << endl;
}

void solve() {
    cin >> n >> k;

    find_young();
}
