//
// Created by 신승민 on 2021/07/02.
//

#include <bits/stdc++.h>

using namespace std;

// 1. have to solve all of N problems.
// 2. problems that have a previous problem, then solve the previous problem first.
// 3. solve as an easy problem first as possible.

typedef vector<int> vi;
typedef vector<pair<int, int>> inp;

vi solve(int n, int m, const inp &input) {
    // designs a graph with n nodes, m edges.

    // topology sort?

    // 1
    // 2 -> 4
    // 3
    // 6 -> 3 -> 2
}

void test1() {
    inp input = {
            make_pair(4, 2),
            make_pair(3, 1),
    };
    vi ret = solve(4, 2, input);
    vi ans{3, 1, 4, 2};

    assert(ret == ans);
}

void test2() {
    inp input = {
            make_pair(1, 2),
    };
    vi ret = solve(5, 1, input);
    vi ans{1, 2, 3, 4, 5};

    assert(ret == ans);
}

void testAll() {
    test1();
    test2();
}

int main() {
    testAll();

    return 0;
}
