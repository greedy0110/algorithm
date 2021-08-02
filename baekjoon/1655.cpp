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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int> A;
    priority_queue<int, vi, greater<>> B;

    RP(_, N) {
        int num;
        cin >> num;

        if (A.empty() || A.top() >= num) {
            A.push(num);
        } else if (B.empty() || B.top() <= num) {
            B.push(num);
        } else {
            A.push(num);
        }

        if (A.size() > B.size() + 1) {
            B.push(A.top());
            A.pop();
        }
        if (B.size() > A.size()) {
            A.push(B.top());
            B.pop();
        }

        cout << A.top() << endl;

//        assert(A.size() >= B.size());
//        assert(A.size() - B.size() <= 1);
//        if (!A.empty() && !B.empty()) assert(A.top() <= B.top());
    }

    return 0;
}
