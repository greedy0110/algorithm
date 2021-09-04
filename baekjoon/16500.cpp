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

string s;
vector<string> words;
vector<int> cache;

int go(int i) {
    if (i == s.size()) return 1;
    int &cac = cache[i];
    if (cac != -1) return cac;

    for (auto &word : words) {
        if (i + word.size() <= s.size()) {
            if (word == s.substr(i, word.size())) {
                if (go(i + (int) word.size()) == 1) return cac = 1;
            }
        }
    }
    return cac = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> s;
    cin >> N;
    cache = vi(s.size(), -1);
    words = vector<string>(N);
    RP(i, N) cin >> words[i];
    cout << go(0) << endl;
    return 0;
}
