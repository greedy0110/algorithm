#include <iostream>
#include <vector>

using namespace std;

int N;
int G[1000][1000];
vector<int> curcuit;

void makeEulerCurcuit(int here) {
    for (int there = 0; there < N; there++) {
        while (G[here][there] != 0) {
            G[here][there]--;
            G[there][here]--;
            makeEulerCurcuit(there);
        }
    }
    curcuit.push_back(here);
}

// 문제의 조건에서 그래프는 모두 하나의 컴포넌트에 존재한다.
// 간선의 갯수가 홀수인 정점이 있다면 -1을 출력한다.
int main() {
    cin >> N;
    bool hasEulerCurcuit = true;
    for (int i=0; i<N; i++) {
        int cnt;
        for (int j=0; j<N; j++) {
            cin >> G[i][j];
            cnt += G[i][j];
        }
        if (cnt%2 != 0) {
            hasEulerCurcuit = false;
        }
    }

    if (hasEulerCurcuit) {
        curcuit = vector<int>();
        makeEulerCurcuit(0);
        for (auto it = curcuit.cbegin(); it != curcuit.cend(); it++) {
            cout << *it + 1 << " ";
        }
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
