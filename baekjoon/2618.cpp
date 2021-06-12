//
// Created by 신승민 on 2021/06/12.
//

#include <bits/stdc++.h>

using namespace std;

#define all(X) begin((X)), end((X))
#define endl '\n'
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define repeat(i, X) for (int i=0; i<((X)); i++)
#define SUPER_BIG numeric_limits<double>::max()

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<string> vs;
typedef priority_queue<int, vi, greater<>> mq;
typedef priority_queue<pii, vpii, greater<>> mpq;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

typedef struct Point {
    int x;
    int y;

    int distance(const Point &other) const {
        return abs(x - other.x) + abs(y - other.y);
    }
} Point;

Point C[1001];
int N, W;
int cache[1001][1001] = {};
int dir[1001][1001] = {};

// c 케이스를 누가 풀어야 하는가?
int slv(int c, int p1, int p2) {
    if (c > W) return 0;

    int &cac = cache[p1][p2];
    if (cac != 0) { return cac; }

    int c1 = slv(c + 1, c, p2);
    if (p1 == 0) c1 += Point{0, 0}.distance(C[c]);
    else c1 += C[p1].distance(C[c]);


    int c2 = slv(c + 1, p1, c);
    if (p2 == 0) c2 += Point{N - 1, N - 1}.distance(C[c]);
    else c2 += C[p2].distance(C[c]);

    if (c1 < c2) {
        // p1, p2 일 때, 선택한 것은?!
        dir[p1][p2] = 1;
        return cac = c1;
    } else {
        dir[p1][p2] = 2;
        return cac = c2;
    }
}

void solve() {
    scanf("%d %d", &N, &W);

    for (int i = 1; i <= W; i++) {
        scanf("%d %d", &C[i].x, &C[i].y);
        C[i].x--;
        C[i].y--;
    }

    printf("%d\n", slv(1, 0, 0));

    int x = 0, y = 0, c = 1;
    while (true) {
        int dr = dir[x][y];
        if (dr == 0) break;
        else if (dr == 1) x = c;
        else if (dr == 2) y = c;
        c++;
        printf("%d\n", dr);
    }
}
