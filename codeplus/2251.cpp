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

int a, b, c;
vector<vb> C;
queue<pair<int, int>> q;

// ac -> b로 부음
// ac,bc -> 용량
pair<int, int> pour(int ta, int tb, int ac, int bc) {
    int reta = 0;
    int retb = tb + ta;
    if (retb > bc) {
        reta = retb - bc;
        retb = bc;
    }
    assert(reta + retb == ta + tb && retb <= bc && reta <= ac);
    return {reta, retb};
}

int remain(pair<int, int> ac) {
    return c - ac.first - ac.second;
}

void check(int xa, int xb) {
    if (!C[xa][xb]) {
        q.push({xa, xb});
        C[xa][xb] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c;
    // C[a][b] => a+b+c == c 인 경우를 탐방함.
    C = vector<vb>(401, vb(401, false));

    C[0][0] = true;
    q.push({0, 0});
    vi ans;

    while (!q.empty()) {
        int ta = q.front().first;
        int tb = q.front().second;
        q.pop();
        int tc = c - ta - tb;
        if (ta == 0) ans.push_back(tc);

        // A -> B
        auto ab = pour(ta, tb, a, b);
        check(ab.first, ab.second);

        // A -> C
        auto ac = pour(ta, tc, a, c);
        check(ac.first, remain(ac));

        // B -> C
        auto bc = pour(tb, tc, b, c);
        check(remain(bc), bc.first);

        // B -> A
        auto ba = pour(tb, ta, b, a);
        check(ba.second, ba.first);

        // C -> A
        auto ca = pour(tc, ta, c, a);
        check(ca.second, remain(ca));

        // C -> B
        auto cb = pour(tc, tb, c, b);
        check(remain(cb), cb.second);
    }

    sort(all(ans));

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
