//
// Created by 신승민 on 2021/07/31.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int N;
vvi L;
vvi T;
vb C;
int order = 0;

void inorder(int root, int depth) {
    int c1 = T[root][0];
    int c2 = T[root][1];

    if (c1 >= 0) inorder(c1, depth + 1);

    L[depth].push_back(order++);
    if (c2 >= 0) inorder(c2, depth + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    T = vvi(N, vector<int>(2));
    L = vvi(10001); // 0 레벨은 없다.
    C = vb(N, false);

    RP(_, N) {
        int p, c1, c2;
        cin >> p >> c1 >> c2;
        p--;
        c1--;
        c2--;

        T[p][0] = c1;
        T[p][1] = c2;
        if (c1 >= 0) {
            C[c1] = true;
        }
        if (c2 >= 0) {
            C[c2] = true;
        }
    }

    int root;
    RP(i, N) {
        if (!C[i]) {
            root = i;
            break;
        }
    }
    inorder(root, 1);

    int ans = 0;
    int ans_level = 1;
    for (int level = 1; level < L.size(); level++) {
        if(L[level].empty()) break;
        int width = L[level].back() - L[level].front() + 1;
        if (width > ans) {
            ans = width;
            ans_level = level;
        }
    }

    cout << ans_level << " " << ans << endl;

    return 0;
}
