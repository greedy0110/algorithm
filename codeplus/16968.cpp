//
// Created by 신승민 on 2021/08/19.
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

string pattern;
string gen;
int cnt = 0;

void go(int index) {
    if (pattern.size() == gen.size()) {
        cnt++;
        return;
    }

    if (pattern[index] == 'c') {
        for (char i = 'a'; i <= 'z'; i++) {
            if (gen.back() == i) continue;
            gen.push_back(i);
            go(index + 1);
            gen.pop_back();
        }
    } else {
        for (char i = '0'; i <= '9'; i++) {
            if (gen.back() == i) continue;
            gen.push_back(i);
            go(index + 1);
            gen.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> pattern;
    go(0);
    cout << cnt << endl;

    return 0;
}
