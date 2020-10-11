#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int M,N;
int board[1000][1000];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs() {
    queue<ii> q = queue<ii>();

    int want_size = 0;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (board[row][col] != -1)
                want_size++;
            if (board[row][col] == 1)
                q.push(ii(row, col));
        }
    }

    int gene = 0;
    int cnt = 0;

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        gene = board[row][col] - 1;
        cnt++;

        for (int i =0; i<4; i++) {
            int nx = row + dx[i];
            int ny = col + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny] == 0) {
                board[nx][ny] = board[row][col] + 1;
                q.push(ii(nx,ny));
            }
        }
    }

    if (cnt != want_size) {
        return -1;
    }

    return gene;
}

int main(int argc, char const *argv[])
{
    cin >> M >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> board[row][col];
        }
    }

    cout << bfs() << endl;

    return 0;
}
