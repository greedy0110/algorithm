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

int calc(string exp, int start, int end) {
    if (start + 1 == end) return exp[start] - '0';

    int ret = exp[start] - '0';
    for (int i = start + 1; i < end; i += 2) {
        char op = exp[i];
        int next = exp[i + 1] - '0';
        if (op == '+') {
            ret += next;
        } else if (op == '-') {
            ret -= next;
        } else {
            ret *= next;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    string exp;
    cin >> N >> exp;
    int numop = N / 2;

    ll ans = -1e11;
    for (int i = 0; i < (1 << numop); i++) {
        vi ops;
        int last = -1;
        bool ok = true;
        for (int j = 0; j < numop; j++) {
            if (i & (1 << j)) {
                ops.push_back(2 * j + 1);
            } else {
                // 괄호 안의 연산이 2개 이상 나오면 무시하자.
                if (last != -1) {
                    if (last + 1 == j) {
                        ok = false;
                    }
                }
                last = j;
            }
        }
        if (!ops.empty() && !ok) continue;


        // 마지막 ops는 계산의 편의를 위해서 넣어준다.
        ops.push_back(N);
        ll ret = calc(exp, 0, ops[0]);
        for (int j = 0; j < ops.size() - 1; j++) {
            int curop = ops[j];
            int nextop = ops[j + 1];

            char op = exp[curop];
            int next = calc(exp, curop + 1, nextop);
            if (op == '+') {
                ret += next;
            } else if (op == '-') {
                ret -= next;
            } else if (op == '*') {
                ret *= next;
            } else {
                assert(false);
            }
        }

        ans = max(ans, ret);
    }

    cout << ans << endl;


    return 0;
}
