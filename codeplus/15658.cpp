//
// Created by 신승민 on 2021/07/31.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int N;
vi A;
vi ans;

void go(int acc, int index, int op1, int op2, int op3, int op4) {
    if (index == N) {
        ans.push_back(acc);
        return;
    }

    if (op1 != 0) go(acc + A[index], index + 1, op1 - 1, op2, op3, op4);
    if (op2 != 0) go(acc - A[index], index + 1, op1, op2 - 1, op3, op4);
    if (op3 != 0) go(acc * A[index], index + 1, op1, op2, op3 - 1, op4);
    if (op4 != 0) go(acc / A[index], index + 1, op1, op2, op3, op4 - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    A = vi(N);
    RP(i, N) cin >> A[i];
    vi ops(4);
    RP(i, 4) cin >> ops[i];

    go(A[0], 1, ops[0], ops[1], ops[2], ops[3]);
    auto ret = minmax_element(all(ans));
    cout << *ret.second << endl << *ret.first << endl;

    return 0;
}
