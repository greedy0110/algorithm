//
// Created by 신승민 on 2021/08/12.
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

struct SkyPoint {
    ll x;
    ll h;
};

struct Building {
    ll lx;
    ll h;
    ll rx;

    bool operator<(const Building &other) const {
        return make_tuple(lx, h, rx) < make_tuple(other.lx, other.h, other.rx);
    }
};

using SkyLine = vector<SkyPoint>;
vector<Building> bs;

void append(SkyLine &line, SkyPoint sp) {
    if (!line.empty()) {
        if (line.back().h == sp.h) {
            return; // 높이가 같으면 무시하자.
        }

        if (line.back().x == sp.x) {
            line.back().h = sp.h;
            return; // x 좌표가 같으면, 가장 마지막으로 들어온 것을 살리자.
        }
    }
    line.push_back(sp);
}

SkyLine getSkyLine(int start, int end) {
    if (start == end) {
        SkyPoint left, right;
        left.x = bs[start].lx;
        left.h = bs[start].h;
        right.x = bs[start].rx;
        right.h = 0;
        return {left, right};
    }

    int mid = (start + end) / 2;
    auto leftLine = getSkyLine(start, mid);
    auto rightLine = getSkyLine(mid + 1, end);

    SkyLine ret;
    ll lh = 0, rh = 0;
    int li = 0, ri = 0;

    while (li < leftLine.size() && ri < rightLine.size()) {
        auto lp = leftLine[li], rp = rightLine[ri];
        if (lp.x < rp.x) {
            lh = lp.h;
            ll h = max(lh, rh);
            append(ret, {lp.x, h});
            li++;
        } else {
            rh = rp.h;
            ll h = max(lh, rh);
            append(ret, {rp.x, h});
            ri++;
        }
    }

    while (li < leftLine.size()) {
        append(ret, leftLine[li++]);
    }

    while (ri < rightLine.size()) {
        append(ret, rightLine[ri++]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    bs = vector<Building>(N);
    RP(i, N) {
        cin >> bs[i].lx >> bs[i].h >> bs[i].rx;
    }
    sort(all(bs));

    auto ans = getSkyLine(0, N - 1);
    for (auto &a: ans) {
        cout << a.x << " " << a.h << " ";
    }
    cout << endl;

    return 0;
}
