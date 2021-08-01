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

vb teach(26, false);
int N, K;
vector<string> words(N);

int go(int k, int cnt) {
    if (teach[k]) {
        return go(k + 1, cnt);
    }

    if (cnt == K) {
        int readable = 0;
        for (auto &word : words) {
            bool ok = true;
            for (char l : word) {
                if (!teach[l - 'a']) {
                    ok = false;
                    break;
                }
            }
            if (ok) readable++;
        }
        return readable;
    }
    if (cnt > K) return 0;
    if (k == 26) return 0;

    int ans = 0;
    teach[k] = true;
    ans = max(ans, go(k + 1, cnt + 1));
    teach[k] = false;
    ans = max(ans, go(k + 1, cnt));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    words = vector<string>(N);
    RP(i, N) cin >> words[i];

    teach['a' - 'a'] = true;
    teach['n' - 'a'] = true;
    teach['t' - 'a'] = true;
    teach['c' - 'a'] = true;
    teach['i' - 'a'] = true;

    cout << go(0, 5) << endl;

//    int N, K;
//    cin >> N >> K;
//    vector<string> words(N);
//    RP(i, N) {
//        cin >> words[i];
//        sort(all(words));
//        words.erase(unique(all(words)), words.end());
//    }
//
//    int ans = 0;
//    for (int i = 0; i < (1 << 26); i++) {
//        vb value(26, false);
//        int cnt = 0;
//        for (int j = 0; j < 26; j++) {
//            if (i & (1 << j)) {
//                value[j] = true;
//                cnt++;
//            }
//        }
//        if (cnt != K) continue;
//        if (!value['a' - 'a'] ||
//            !value['n' - 'a'] || !value['t' - 'a'] || !value['i' - 'a'] || !value['c' - 'a'])
//            continue;
//
//        int readable = 0;
//        for (auto &word : words) {
//            bool ok = true;
//            for (char l : word) {
//                if (!value[l - 'a']) {
//                    ok = false;
//                    break;
//                }
//            }
//            if (ok) readable++;
//        }
//        ans = max(ans, readable);
//    }
//
//    cout << ans << endl;

    return 0;
}
