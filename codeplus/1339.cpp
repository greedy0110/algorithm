//
// Created by 신승민 on 2021/07/31.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int value[256];
vector<string> words;

int calc() {
    int sum = 0;
    for (auto &word: words) {
        int cur = 0;
        for (char l : word) {
            cur = cur * 10 + value[l];
        }
        sum += cur;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    words = vector<string>(N);
    vector<char> letters;
    RP(i, N) {
        cin >> words[i];
        letters.insert(letters.end(), all(words[i]));
    }

    sort(all(letters));
    letters.erase(unique(all(letters)), letters.end());
    vector<int> matches(letters.size());
    for (int i = 0; i < letters.size(); i++) {
        matches[i] = 9 - i;
    }

    int ans = -1;
    do {
        RP(i, letters.size()) {
            value[letters[i]] = matches[i];
        }
        ans = max(ans, calc());
    } while (prev_permutation(all(matches)));

    cout << ans << endl;

    return 0;
}
