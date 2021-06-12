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

ll _hash(const Point &a, const Point &b) {
    return N * N * N * (ll) a.x + N * N * (ll) a.y + N * (ll) b.x + (ll) b.y;
}

// [case #][a hash code of 2 Points] = slv.
map<ll, int> cache[1001];

int slv(int c, const Point &p1, const Point &p2) {
    if (c == W) return 0;

    int phash = _hash(p1, p2);
    if (cache[c].find(phash) != cache[c].end()) {
        return cache[c][phash];
    }

    Point &pc = C[c];

    int c1 = pc.distance(p1) + slv(c + 1, pc, p2);
    int c2 = pc.distance(p2) + slv(c + 1, p1, pc);

    if (c1 < c2) {
        return c1;
    }

    return c2;
}

void solve() {
    scanf("%d %d", &N, &W);

    for (int i = 1; i <= W; i++) {
        scanf("%d %d", &C[i].x, &C[i].y);
        C[i].x--;
        C[i].y--;
    }

    int dp[1001][1001];
    int dir[1001][1001];
    dp[0][0] = 0;
    dir[0][0] = -1;

    Point p1{0, 0}, p2{N - 1, N - 1};

    C[0] = Point{0, 0};
    for (int i = 1; i <= W; i++) {
        dp[i][0] = dp[i - 1][0] + C[i - 1].distance(C[i]);
        dir[i][0] = 0;
    }

    C[0] = Point{N - 1, N - 1};
    for (int i = 1; i <= W; i++) {
        dp[0][i] = dp[0][i - 1] + C[i - 1].distance(C[i]);
        dir[0][i] = 1;
    }

    for (int x = 1; x <= W; x++) {
        for (int y = 1; y <= W; y++) {
            int c1 = dp[x - 1][y] + C[x - 1].distance(C[x]);
            if (x - 1 == 0) {
                c1 = dp[x - 1][y] + p1.distance(C[x]);
            }

            int c2 = dp[x][y - 1] + C[y - 1].distance(C[y]);
            if (y - 1 == 0) {
                c2 = dp[x][y - 1] + p2.distance(C[y]);
            }

            if (c1 < c2) {
                dir[x][y] = 0;
                dp[x][y] = c1;
            } else {
                dir[x][y] = 1;
                dp[x][y] = c2;
            }
        }
    }

    for (int x = 0; x <= W; x++) {
        for (int y = 0; y <= W; y++) {
            printf("%d ", dp[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    for (int x = 0; x <= W; x++) {
        for (int y = 0; y <= W; y++) {
            printf("%d ", dir[x][y]);
        }
        printf("\n");
    }

    int ans = INT_MAX;
    int ansx, ansy;
    for (int i = 0; i <= W; i++) {
        if (dp[i][W - i] < ans) {
            ans = dp[i][W - i];
            ansx = i;
            ansy = W - i;
        }
    }
    printf("%d\n", ans);

    vi rev_his;
    while (ansx >= 0 && ansy >= 0) {
        int dr = dir[ansx][ansy];
        if (dr == -1) break;

        rev_his.push_back(dr + 1);

        if (dr == 0) ansx--;
        if (dr == 1) ansy--;
    }
    reverse(all(rev_his));
    for (int his : rev_his) {
        printf("%d\n", his);
    }
}
