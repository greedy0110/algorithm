//
// Created by 신승민 on 2021/09/01.
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

    set<string> a, b;
    vector<string> words;
    int N, M;
    cin >> N >> M;
    string word;
    RP(_, N) {
        cin >> word;
        a.insert(word);
    }
    RP(_, M) {
        cin >> word;
        auto found = a.find(word);
        if (found != a.end()) {
            words.push_back(*found);
        }
    }
    sort(all(words));
    cout << words.size() << endl;
    for (auto &w: words) {
        cout << w << endl;
    }


    return 0;
}
