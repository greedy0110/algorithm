//
// Created by 신승민 on 2021/08/29.
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

vi preprocessing(string p) {
    // fail 함수를 만든다.
    // fail[i] =>
    //  P의 i까지의 부분 문자열에서
    //  prefix == suffix를 만족하는
    //  부분 문자열 중에서 가장 긴 것의 길이.

    // fail[i] => i에서 값의 불일치가 발생했다면, 다음 확인해야할 i의 위치.
    int m = p.size();
    vi fail(m);
    fail[0] = 0;
    int j = 0;
    for (int i = 1; i < m; i++) {
        // p[i]는 이번에 부분 문자열에 추가되는 값.
        //  이 값은 suffix의 마지막 값이 될 것이다.

        // j는 가장 최근에 발견된 fail 함수의 값.
        //  이 값은 p[0..j-1] 와 p[i-j..i-1] 가 같다는 것을 의미한다.

        while (j > 0 && p[i] != p[j]) j = fail[j - 1];
        if (p[i] == p[j]) {
            // 그러한 상태에서 p[i]와 p[j]가 같으면? 당연히 p[i-j..i], p[0..j]가 같고. 이는 fail[i] = j+1 이라는 것을 의미한다.
            fail[i] = j + 1;
            j += 1;
        } else {
            fail[i] = 0;
        }
    }
    return fail;
}

vi kmp(string s, string p) {
    // s 에서, p 패턴이 시작되는 모든 시작 위치를 담은 배열을 반환한다.

    auto fail = preprocessing(p);
    vi ans;
    int n = s.size(), m = p.size(), j = 0;
    for (int i = 0; i < n; i++) {
        // i: s 문자열 탐색하려는 위치.
        // j: p 문자열에서 탐색하야 하는 다음 위치.

        // s[i] != p[j] 라는 뜻은... 다시 탐색을 시작해야 한다는 의미이다.
        //  그런데 우리는 pi를 가지고 있으므로, 다음과 같은 것을 생략할 수 있는데.

        // 현재 글자가 불일치하면 fail 값을 계속 따라감.
        while (j > 0 && s[i] != p[j]) j = fail[j - 1];

        // 현재 글자가 일치
        if (s[i] == p[j]) {
            // p를 s[i-m+1..i] 에서 찾음.
            if (j == m - 1) { // 문자열을 완성했으면.
                ans.push_back(i - m + 1); // s[x..i] 가 p와 같으므로. i-x == m-1, x = i-m+1
                // 다음 비교는 여기서 찾지 못한 것과 마찬가지로 j를 이동시키자.
                j = fail[j];
            } else {
                j += 1;
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, p;
    cin >> s >> p;
    cout << (kmp(s, p).empty() ? 0 : 1) << endl;

    return 0;
}
