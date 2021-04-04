#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int N;
char m[100][100];
vector<vector<bool> > visited;
int dy[] = {1,0,-1,0};
int dx[] = {0,-1,0, 1};

bool inMap(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

void dfs(int y, int x, set<char> ch) {
    queue<pair<int, int> > q;
    q.push(make_pair(y,x));
    visited[y][x] = true;
    while (!q.empty()) {
        int cy = q.front().first, cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy+dy[i], nx = cx+dx[i];
            if (inMap(ny, nx) && (ch.find(m[ny][nx]) != ch.end()) && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(make_pair(ny,nx));
            }
        }
    }
}

void clearVisited() {
    visited = vector<vector<bool> >(N, vector<bool>(N, false));
}

int dfsAll(set<char> ch) {
    clearVisited();
    int cnt = 0;
    for (int y=0;y<N;y++) {
        for (int x=0;x<N;x++) {
            if ((ch.find(m[y][x]) != ch.end()) && !visited[y][x]) {
                dfs(y,x, ch);
                cnt++;
            }
        }
    }
    return cnt;
}

void process() {
    int r = dfsAll({'R'});
    int g = dfsAll({'G'});
    int b = dfsAll({'B'});
    int rg = dfsAll({'R', 'G'});

    cout << r + g + b << " " << rg + b << endl;
}

int main() {
    cin >> N;
    string line;
    for (int y=0;y<N;y++) {
        cin >> line;
        for (int x=0;x<N;x++) {
            m[y][x] = line[x];
        }
    }
    process();
    return 0;
}

