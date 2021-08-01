//
// Created by 신승민 on 2021/08/01.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int pc = 0;
    string str;
    cin >> str;
    for (int i = 0; i < str.size() - 1; i++) {
        char l = str[i];
        if (l == 'P') {
            pc++;
        } else {
            pc -= 2;
            if (pc < 0) {
                cout << "NP" << endl;
                return 0;
            }
        }
    }
    if (pc == 0 && str.back() == 'P') cout << "PPAP" << endl;
    else cout << "NP" << endl;

    return 0;
}
