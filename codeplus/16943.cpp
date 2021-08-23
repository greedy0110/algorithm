//
// Created by 신승민 on 2021/08/23.
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

    string A;
    int B;
    cin >> A >> B;
    vi C(A.size());
    RP(i, A.size()) C[i] = i;

    int ans = -1;
    do {
        if (A[C[0]] == '0') continue;

        string temp;
        for (int index : C) {
            temp.push_back(A[index]);
        }

//        int cur = 0;
//        for (int index : C) {
//            cout << A[index];
//            cur += 10 * cur + (A[index] - '0');
//        }
//        cout << endl;
//
//        cout << cur << endl;
        int cur = stoi(temp);

        if (cur < B) {
            ans = max(ans, cur);
        }
    } while (next_permutation(all(C)));

    cout << ans << endl;

    return 0;
}
