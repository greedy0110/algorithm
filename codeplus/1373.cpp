//
// Created by 신승민 on 2021/07/18.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string bi;
    cin >> bi;
    int N = bi.size();

    vector<int> result;
    for (int i = N - 1; i >= 0; i -= 3) {
        int num = bi[i] - '0';
        if (i - 1 >= 0) num += 2 * (bi[i - 1] - '0');
        if (i - 2 >= 0) num += 4 * (bi[i - 2] - '0');
        result.push_back(num);
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}
