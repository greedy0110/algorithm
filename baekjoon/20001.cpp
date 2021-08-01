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

    string str;

    int cnt = 0;
    while (true) {
        getline(cin, str);
        if (str == "고무오리 디버깅 시작") continue;
        else if (str == "고무오리 디버깅 끝") break;
        else if (str == "문제") cnt++;
        else if (str == "고무오리") {
            if (cnt == 0) cnt += 2;
            else cnt--;
        }
    }

    if (cnt == 0) cout << "고무오리야 사랑해" << endl;
    else cout << "힝구" << endl;

    return 0;
}
