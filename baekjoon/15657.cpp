//
// Created by 신승민 on 2021/04/11.
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

int arr[10];
int N, M;

// 각 vi 요소의 길이가 k 인 vvi 를 반환할 것
vvi comb(int n, int k) {
    if (k == 1) {
        vvi ret;

        for (int i = n; i <= N; i++)
            ret.push_back(vi(1, arr[i]));

        return ret;
    }
    if (n == N) {
        return vvi(1, vi(k, arr[n]));
    }

    vvi ret;
    for (int i = n; i <= N; i++) {
        vvi part = comb(i, k - 1);
        for (auto &pa: part) {
            vi merge;
            merge.push_back(arr[i]);
            move(all(pa), back_inserter(merge));
            ret.push_back(merge);
        }
    }

    return ret;
}

void solve() {
    cin >> N >> M;

    repeat(i, N) {
        cin >> arr[i + 1];
    }

    sort(arr + 1, arr + 1 + N);

    for (auto &ret : comb(1, M)) {
        for (auto i : ret) {
            cout << i << " ";
        }
        cout << endl;
    }
}
