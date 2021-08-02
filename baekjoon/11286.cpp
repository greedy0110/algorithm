//
// Created by 신승민 on 2021/08/02.
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

struct element {
    int num;

    bool operator()(const element &a, const element &b) {
        int aa = abs(a.num);
        int ab = abs(b.num);

        if (aa == ab) {
            return a.num > b.num;
        }

        return aa > ab;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    custom_pq(element) pq;

    int N;
    cin >> N;
    RP(_, N) {
        element temp;
        cin >> temp.num;
        if (temp.num != 0) {
            pq.push(temp);
        } else if (pq.empty()) {
            cout << 0 << endl;
        } else {
            cout << pq.top().num << endl;
            pq.pop();
        }
    }

    return 0;
}
