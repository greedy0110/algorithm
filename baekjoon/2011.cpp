//
// Created by 신승민 on 2021/07/06.
//

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000;
string input;
int cache[5001] = {};

bool isPossible1(int p) {
    return input[p] != '0';
}

bool isPossible2(int p) {
    if (int(input.size()) - 2 >= p) {
        assert(p <= input.length() - 2);
        int f = input[p] - '0';
        int s = input[p + 1] - '0';
        return 10 * f + s <= 26;
    }
    return false;
}

int numP(int p) {
    if (p >= input.size()) return 1;

    int &cac = cache[p];
    if (cac != 0) return cac;

    int ans = 0;
    if (isPossible1(p)) {
        ans += numP(p + 1);
        if (isPossible2(p)) ans += numP(p + 2);
    }

    return cac = ans % MOD;
}

int main() {
    cin >> input;

    cout << numP(0);

    return 0;
}
