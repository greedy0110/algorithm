//
// Created by 신승민 on 2021/07/06.
//

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000;
string input;

int main() {
    cin >> input;

    int dp[5002] = {};

    dp[0] = 1;
    dp[1] = input[0] != '0' ? 1 : 0;
    for (int i = 2; i <= input.size(); i++) {
        int a = input[i - 2] - '0';
        int b = input[i - 1] - '0';

        if (b != 0) dp[i] += dp[i - 1];
        if (a != 0 && a * 10 + b <= 26) dp[i] += dp[i - 2];
        dp[i] %= MOD;
    }

    cout << dp[input.size()] << endl;

    return 0;
}
