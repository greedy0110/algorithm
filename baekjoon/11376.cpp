//
// Created by 신승민 on 2021/10/01.
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
typedef pair<int, int> pii;

vvi g;
vi personFrom, workFrom;
vb visited;

bool biMatching(int person) {
    visited[person] = true;
    for (int work : g[person]) {
        int against = personFrom[work];
        if (against == -1 || !visited[against] && biMatching(against)) {
            workFrom[person] = work;
            personFrom[work] = person;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int numPeople, numWork;
    cin >> numPeople >> numWork;

    g = vvi(numPeople);
    personFrom = vi(numWork, -1);
    workFrom = vi(numPeople, -1);

    RP(person, numPeople) {
        int num;
        cin >> num;
        RP(_, num) {
            int work;
            cin >> work;
            g[person].push_back(work - 1);
        }
    }

    int match = 0;
    RP(person, numPeople) {
        // 사람에 일이 안할당 되어있다면?
        if (workFrom[person] == -1) {
            // 할 일을 찾아보자.
            visited = vb(numPeople, false);
            if (biMatching(person)) match++;
        }
    }
    cout << match << endl;

    return 0;
}
