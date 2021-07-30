//
// Created by 신승민 on 2021/07/30.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

vector<int> G[3000];

// -1: 방문 안함, 1: 방문함, 2: 사이클에 속함.
vector<int> T;

// -2: 사이클 찾음, 포함되지 않음, -1: 사이클 못 찾음, 0~N-1: 사이클 찾았고, 사이클 시작 정점.
int go(int from, int to) {
    if (T[to] == 1) return to;
    T[to] = 1;

    for (int next : G[to]) {
        if (from == next) continue;
        int result = go(to, next);

        if (result == to) {
            T[to] = 2;
            return -2;
        }
        if (result >= 0) {
            T[to] = 2;
            return result;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    T = vector<int>(N, -1);
    RP(_, N) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 1. 싸이클에 속한 점 찾기
    go(-1, 0);

    // 2. 싸이클에 속한 모든 점을 D = 0으로 설정하고 BFS 구하기.
    int D[3001];
    queue<int> q;
    RP(i, N) {
        if (T[i] == 2) {
            D[i] = 0;
            q.push(i);
        } else {
            D[i] = -1;
        }
    }

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        for (int nc : G[c]) {
            if (D[nc] != -1) continue;
            D[nc] = D[c] + 1;
            q.push(nc);
        }
    }

    RP(i, N) cout << D[i] << " ";
    cout << endl;

    return 0;
}
