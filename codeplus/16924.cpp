//
// Created by 신승민 on 2021/08/19.
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

    vi cs;
    char A[101][101];
    int N, M;
    cin >> N >> M;
    RP(x, N) {
        string temp;
        cin >> temp;
        RP(y, M) {
            A[x + 1][y + 1] = temp[y];
        }
    }

    for (int i = 3; i <= 100; i += 2) {
        cs.push_back(i);
    }

    vector<tuple<int, int, int>> ans;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= M; y++) {
            for (int i = 1; i <= cs.size(); i++) {
                int size = cs[i - 1];
                if (x + size > N || y + size > M) break;
                int m = size / 2;
                bool ok = true;
                for (int sm = x; sm < x + size; sm++) {
                    for (int sy = y; sy < y + size; sy++) {
                        if ((sm == x + m || sy == y + m) && A[sm][sy] == '.') ok = false;
                        if (sm != x + m && sy != y + m && A[sm][sy] == '*') ok = false;
                    }
                    if (!ok) break;
                }
                if (ok) ans.push_back({x + m, y + m, i});
            }
        }
    }

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        for (auto a : ans) {
            cout << get<0>(a) << " ";
            cout << get<1>(a) << " ";
            cout << get<2>(a) << endl;
        }
    }

    return 0;
}
