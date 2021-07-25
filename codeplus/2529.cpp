//
// Created by 신승민 on 2021/07/25.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int K;
char A[10];
bool V[10];

vector<string> ans;

void go(string num) {
    if (num.size() == K + 1) {
        ans.push_back(num);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (V[i]) continue;

        if (!num.empty()) {
            int idx = num.size() - 1;
            int left = num[idx] - '0';
            if (A[idx] == '>' && left < i) continue;
            if (A[idx] == '<' && left > i) continue;
        }

        V[i] = true;
        num.push_back(i + '0');
        go(num);
        num.pop_back();
        V[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> K;
    RP(i, K) cin >> A[i];
    go("");

    cout << ans.back() << endl << ans.front() << endl;

    return 0;
}
