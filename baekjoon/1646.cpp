//
// Created by 신승민 on 2021/08/14.
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

vector<ll> fn;

void calcFn(int n) {
    fn.push_back(1);
    fn.push_back(1);
    for (int i = 2; i <= n; i++) {
        fn.push_back(fn[i - 1] + fn[i - 2] + 1);
    }
}

string path(int index, ll root, ll e) {
    if (root == e) return "";
    assert(index >= 2); // index = 0, index = 1 이면, 이미 찾았어야 한다.
    ll left_root = root + 1;
    ll right_root = root + fn[index - 2] + 1;

    if (right_root <= e) {
        return "R" + path(index - 1, right_root, e);
    } else {
        return "L" + path(index - 2, left_root, e);
    }
}

pair<int, ll> go(int index, ll root, ll s, ll e) {
    if (index == 0 || index == 1) {
        // s와 e의 공통 조상을 찾는 함수,
        // s와 e는 같은 수가 아님.
        // index 0, index 1은 말이 안됌.
        return {-1, -1};
    }
    if (root == s) return {index, s};
    if (root == e) return {index, e};

    ll left_root = root + 1;
    ll right_root = root + fn[index - 2] + 1;

    if (right_root <= s && right_root <= e) {
        return go(index - 1, right_root, s, e);
    } else if (right_root <= s || right_root <= e) {
        return {index, root};
    } else {
        return go(index - 2, left_root, s, e);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    ll s, e;
    cin >> s >> e;

    if (N == 0 || N == 1) {
        return 0;
    }

    calcFn(N);
    auto fd = go(N, 1LL, s, e);
    int index = fd.first;
    ll root = fd.second;

    string up = path(index, root, s);
    string down = path(index, root, e);
    string ans;
    for (int i = 0; i < up.size(); i++) {
        ans += "U";
    }
    ans += down;
    cout << ans << endl;

    return 0;
}
