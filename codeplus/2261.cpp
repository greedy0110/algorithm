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
typedef pair<int, int> pii;

vector<pii> pts;

ll dist(pii i, pii j) {
    return (i.first - j.first) * (i.first - j.first) + (i.second - j.second) * (i.second - j.second);
}

ll go(int left, int right) {
    if (right - left + 1 <= 3) {
        ll ans = 4e18;
        for (int i = left; i <= right; i++) {
            for (int j = i + 1; j <= right; j++) {
                ans = min(ans, dist(pts[i], pts[j]));
            }
        }
        return ans;
    }

    int mid = (left + right) / 2;
    ll dl = go(left, mid), dr = go(mid + 1, right);
    ll ans = min(dl, dr);

    // 중심 기준으로 왼쪽, 오른쪽으로 d 거리 이내에 있는 친구를 찾자.
    vector<pii> psb;
    for (int i = left; i <= right; i++) {
        int d = pts[i].first - pts[mid].first;
        if (d * d < ans) {
            psb.push_back(pts[i]);
        }
    }

    sort(all(psb), [&](const pii &a, const pii &b) {
        return a.second < b.second;
    }); // y 기준으로 정렬한다.
    for (int i = 0; i < psb.size(); i++) {
        for (int j = i + 1; j < psb.size(); j++) {
            int y = psb[i].second - psb[j].second;
            if (y * y < ans) {
                ll d = dist(psb[i], psb[j]);
                ans = min(ans, d);
            } else {
                break; // 더 이동해봤자. 절대 답이 아니다. y 축을 기준으로 이미 답 범위를 넘어섬.
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    pts = vector<pii>(N);
    RP(i, N) {
        cin >> pts[i].first >> pts[i].second;
    }
    sort(all(pts));
    cout << go(0, N - 1) << endl;

    return 0;
}
