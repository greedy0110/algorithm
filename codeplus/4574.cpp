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
typedef vector<vb> vvb;
typedef long long ll;

const int H = 9;
vvb DM;
vvi B;

bool check() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vb cl(10, false);
            for (int x = 3 * i; x < 3 * (i + 1); x++) {
                for (int y = 3 * j; y < 3 * (j + 1); y++) {
                    if (B[x][y] == -1) continue;
                    if (cl[B[x][y]]) return false;
                    cl[B[x][y]] = true;
                }
            }
        }
    }

    RP(x, H) {
        vb cl(10, false);
        RP(y, H) {
            if (B[x][y] == -1) continue;
            if (cl[B[x][y]]) return false;
            cl[B[x][y]] = true;
        }
    }

    RP(x, H) {
        vb cl(10, false);
        RP(y, H) {
            if (B[x][y] == -1) continue;
            if (cl[B[x][y]]) return false;
            cl[B[x][y]] = true;
        }
    }
    RP(y, H) {
        vb cl(10, false);
        RP(x, H) {
            if (B[x][y] == -1) continue;
            if (cl[B[x][y]]) return false;
            cl[B[x][y]] = true;
        }
    }
    return true;
}

bool go(int index) {
//    RP(x, H) {
//        RP(y, H) {
//            if (B[x][y] == -1) cout << 0;
//            else cout << B[x][y];
//        }
//        cout << endl;
//    }
//    cout << endl;
    if (index == H * H) {
        if (check()) {
            RP(x, H) {
                RP(y, H) {
                    cout << B[x][y];
                }
                cout << endl;
            }
            return true;
        }
        return false;
    }

    int x = index / H;
    int y = index % H;

    if (B[x][y] != -1) {
        return go(index + 1);
    }

    vector<pair<int, int>> ad;
    for (int i = 1; i <= 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            if (DM[i][j]) continue;
            ad.push_back({i, j});
        }
    }

    for (auto &d: ad) {
        int i = d.first;
        int j = d.second;
        DM[i][j] = true;

        if (x + 1 < H && B[x + 1][y] == -1) {
            B[x][y] = i;
            B[x + 1][y] = j;
            if (check()) if (go(index + 1)) return true;

            B[x][y] = j;
            B[x + 1][y] = i;
            if (check()) if (go(index + 1)) return true;

            B[x][y] = -1;
            B[x + 1][y] = -1;
        }

        if (y + 1 < H && B[x][y + 1] == -1) {
            B[x][y] = i;
            B[x][y + 1] = j;
            if (check()) if (go(index + 1)) return true;

            B[x][y] = j;
            B[x][y + 1] = i;
            if (check()) if (go(index + 1)) return true;

            B[x][y] = -1;
            B[x][y + 1] = -1;
        }

        DM[i][j] = false;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int level = 1;
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        B = vvi(H, vi(H, -1));
        DM = vvb(10, vb(10, false));

        RP(_, N) {
            int i, j;
            string ip, jp;
            cin >> i >> ip >> j >> jp;

            int xi = ip[0] - 'A';
            int yi = ip[1] - '1';

            int xj = jp[0] - 'A';
            int yj = jp[1] - '1';

            B[xi][yi] = i;
            B[xj][yj] = j;
            if (i > j) swap(i, j);
            DM[i][j] = true;
        }

        for (int i = 1; i <= 9; i++) {
            string p;
            cin >> p;
            int x = p[0] - 'A';
            int y = p[1] - '1';
            B[x][y] = i;
        }

        cout << "Puzzle " << level++ << endl;
        go(0);
    }

    return 0;
}
