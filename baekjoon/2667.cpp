#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int m[25][25];
bool visited[25][25] = {{false}};
int dy[] = {1,0,-1,0};
int dx[] = {0,-1,0, 1};

bool inMap(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int dfs(int y, int x) {
    queue<pair<int, int> > q;
    q.push(make_pair(y,x));
    visited[y][x] = true;
    int cnt = 0;
    while (!q.empty()) {
        int cy = q.front().first, cx = q.front().second;
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int ny = cy+dy[i], nx = cx+dx[i];
            if (inMap(ny, nx) && m[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(make_pair(ny,nx));
            }
        }
    }

    return cnt;
}

void dfsAll() {
    vector<int> ret;

    for (int y=0;y<N;y++) {
        for (int x=0;x<N;x++) {
            if (m[y][x] == 1 && !visited[y][x]) {
                ret.push_back(dfs(y,x));
            }
        }
    }

    sort(ret.begin(), ret.end());
    cout << ret.size() << endl;
    for (auto i = ret.cbegin(); i != ret.cend(); i++) {
        cout << *i << endl;
    }
}

int main() {
    cin >> N;
    string line;
    for (int y=0;y<N;y++) {
        cin >> line;
        for (int x=0;x<N;x++) {
            m[y][x] = line[x] - '0';
        }
    }
    dfsAll();
    return 0;
}
