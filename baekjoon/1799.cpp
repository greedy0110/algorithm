//
// Created by 신승민 on 2021/08/08.
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

int N;
int A[10][10];
int colors[10][10];

bool pp[30], mm[30];

bool is_check(int x, int y) {
    return !pp[y - x + N - 1] && !mm[x + y];
}

int go(int index, int cnt, int color) {
    if (index >= N * N) {
        return cnt;
    }

    int x = index / N, y = index % N;
    if (A[x][y] == 0) {
        return go(index + 1, cnt, color);
    }
    if (colors[x][y] != color) {
        return go(index + 1, cnt, color);
    }

    int ans = go(index + 1, cnt, color);
    if (is_check(x, y)) {
        mm[x + y] = pp[y - x + N - 1] = true;
        ans = max(ans, go(index + 1, cnt + 1, color));
        mm[x + y] = pp[y - x + N - 1] = false;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int startColor = 0;
    RP(x, N) {
        int color = startColor;
        RP(y, N) {
            cin >> A[x][y];
            colors[x][y] = color;
            color = 1 - color;
        }
        startColor = 1 - startColor;
    }
    cout << go(0, 0, 0) + go(1, 0, 1) << endl;

    return 0;
}
