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

struct Meeting {
    int s;
    int f;
};

bool cmp(const Meeting &a, const Meeting &b) {
    if (a.f == b.f) {
        return a.s < b.s;
    }
    return a.f < b.f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<Meeting> ms(N);
    RP(i, N) {
        int s, f;
        cin >> s >> f;
        ms[i] = {s, f};
    }
    sort(all(ms), cmp);
    int now = 0;
    int cnt = 0;
    for (auto &m : ms) {
        if (m.s >= now) {
            now = m.f;
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
