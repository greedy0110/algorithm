//
// Created by 신승민 on 2021/08/31.
//

//TODO: 왜 처음의 이분 탐색 식으로는 해결이 불가능 했을까?
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
vvi A;
vvi H;
int sx, sy;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int max_height = 0, min_height = 1000000;
int total_k = 0;

bool in_board(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

bool bfs(int minh, int maxh) { // O(N^2)
    if (H[sx][sy] < minh || H[sx][sy] > maxh) return false;

    vvi D(N, vi(N, -1));
    queue<pair<int, int>> q;
    D[sx][sy] = 0;
    q.push({sx, sy});

    int cnt = 0;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        int cd = D[cx][cy];
        if (A[cx][cy] == 'K') cnt++;

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (in_board(nx, ny)) {
                if (D[nx][ny] == -1 && minh <= H[nx][ny] && H[nx][ny] <= maxh) {
                    D[nx][ny] = cd + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    return total_k == cnt;
}

bool possible(int x) {
    // x 피로도로 방문이 모든 K에 방문할 수있나?
    for (int min = 1; min <= max_height - x; min++) { // 10^6
        if (bfs(min, min + x)) return true; // O(N^2)
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    A = vvi(N, vi(N));
    H = vvi(N, vi(N));
    vi h;

    RP(x, N) {
        string temp;
        cin >> temp;
        RP(y, N) {
            A[x][y] = temp[y];
            if (A[x][y] == 'P') {
                sx = x;
                sy = y;
            }
            if (A[x][y] == 'K') {
                total_k++;
            }
        }
    }
    RP(x, N) {
        RP(y, N) {
            cin >> H[x][y];
            h.push_back(H[x][y]);
            max_height = max(max_height, H[x][y]);
            min_height = min(min_height, H[x][y]);
        }
    }

    sort(all(h));
    h.erase(unique(all(h)), h.end());

    int left = 0, right = 0;
    int ans = -1;
    while (right < h.size()) {
        assert (left <= right);
        if (bfs(h[left], h[right])) {
            if (ans == -1) ans = h[right] - h[left];
            else ans = min(ans, h[right] - h[left]);
            left++;
            if (left > right) right = left;
        } else {
            right++;
        }
    }
    cout << ans << endl;

//    int left = 0, right = max_height - min_height, ans;
//    // 처음으로 true 가 되는 값 찾기
//    while (left <= right) { // O((log10^6) * N^2 * 10^6)
//        int mid = (left + right) / 2;
//        if (possible(mid)) { // 답은 left ... mid
//            ans = mid;
//            right = mid - 1;
//        } else {
//            left = mid + 1;
//        }
//    }
//    cout << ans << endl;

    return 0;
}
