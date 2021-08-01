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

    int N;
    cin >> N;

    int ans = 0;
    while (N--) {
        string str;
        cin >> str;
        bool ok = true;

        int ac = 0, bc = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'A') ac++;
            else bc++;
        }

        if (ac % 2 != 0 || bc % 2 != 0) continue;


        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'A') ac++;
            else bc++;
        }
    }

    cout << ans;

    return 0;
}
