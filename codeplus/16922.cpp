//
// Created by 신승민 on 2021/08/19.
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

set<int> ans;
int values[] = {1, 5, 10, 50};

void go(int remain, int order, int sum) {
    if (remain == 0) {
        ans.insert(sum);
        return;
    }

    if (order == 4) {
        return;
    }

    for (int i = 0; i <= remain; i++) {
        int cost = values[order] * i;
        go(remain - i, order + 1, sum + cost);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    go(N, 0, 0);
    cout << ans.size() << endl;

    return 0;
}
