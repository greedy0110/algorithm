//
// Created by 신승민 on 2021/08/23.
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

bool psb(int H, int W, int r, int c) {
    return r <= H && c <= W;
}

bool psb2(int H, int W, int r1, int c1, int r2, int c2) {
    return psb(H, W, r1, c1) && (psb(H - r1, W, r2, c2) || psb(H, W - c1, r2, c2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W, N;
    cin >> H >> W >> N;
    vector<pair<int, int>> S(N);
    RP(i, N) {
        cin >> S[i].first >> S[i].second;
    }

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    vi choose(N, 0);
    choose[0] = 1;
    choose[1] = 1;

    int ans = 0;
    // N개 중에 2개 고르기
    do {
        vi chs;
        RP(i, N) {
            if (choose[i] == 1) chs.push_back(i);
        }
        assert(chs.size() == 2);
        int p1 = chs[0], p2 = chs[1];

        // 배치해보기. (총 4개의 케이스 가능.)
        int r1 = S[p1].first, c1 = S[p1].second;
        int r2 = S[p2].first, c2 = S[p2].second;

        if (psb2(H, W, r1, c1, r2, c2) ||
            psb2(H, W, c1, r1, r2, c2) ||
            psb2(H, W, r1, c1, c2, r2) ||
            psb2(H, W, c1, r1, c2, r2)) {
            ans = max(ans, r1 * c1 + r2 * c2);
        }

        // 넓이의 최댓값.

    } while (prev_permutation(all(choose)));

    cout << ans << endl;

    return 0;
}
