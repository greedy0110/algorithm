//
// Created by 신승민 on 2021/09/02.
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

    int A[101][101];
    bool V[101][101];
    int N;
    cin >> N;
    RP(x, N) RP(y, N) {
            cin >> A[x][y];
            V[x][y] = false;
        }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (V[i][j]) continue; // 이미 방문할 수 있음을 확인했다면, 거르자.
            // i -> j 까지 갈 수 있는가? (bfs 를 하면된다.)
            queue<int> q;
            vb visited(N, false);
//            visited[i] = true; // 자기 자신은 방문 체크 안한다. 순회해서 돌아오는 것을 알아야 한다.
            q.push(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int k = 0; k < N; k++) {
                    if (A[cur][k] == 0) continue;
                    if (visited[k]) continue;
                    visited[k] = true;
                    q.push(k);
                }
            }
            if (visited[j]) V[i][j] = true;
        }
    }

    RP(i, N) {
        RP(j, N) {
            cout << (V[i][j] ? 1 : 0) << " ";
        }
        cout << endl;
    }

    return 0;
}
