//
// Created by 신승민 on 2021/09/03.
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

int N;
vi sqs;
vvi cache;

bool go(int num, int size) {
    int &cac = cache[num][size];
    if (cac != -1) return cac;

    if (size == 1) return cac = binary_search(all(sqs), num);

    // 자기 자신과 같거나 큰 값에 붙어있을 것.
    int low_index = lower_bound(all(sqs), num) - sqs.begin();
    for (int i = low_index-1; i >= 0; i--) {
        assert(num - sqs[i] >= 1);
        if (go(num - sqs[i], size - 1)) return cac = true;
    }
    return cac = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cache = vvi(50001, vi(5, -1));
    for (int i = 1; i * i <= N; i++) {
        sqs.push_back(i * i);
    }
    for (int i = 1; i <= 4; i++) {
        if (go(N, i)) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
