//
// Created by 신승민 on 2021/09/03.
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    map<string, string> dict;
    RP(_, N) {
        string site, pwd;
        cin >> site >> pwd;
        dict[site] = pwd;
    }
    RP(_, M) {
        string site;
        cin >> site;
        cout << dict[site] << endl;
    }

    return 0;
}
