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
int num_books, num_people;
// personIsFrom[b] -> b와 매치되는 a반환
// bookIsFrom[a] -> a와 매치되는 b반환
vi personIsFrom, bookIsFrom;
vb visited;

bool dfs(int person) {
    visited[person] = true;
    for (int book : g[person]) {
        int against = personIsFrom[book];
        // 반대편이 매칭되지 않음 (against == -1)
        // 매칭되어 있었지만, 원래 매칭되어 있던 정점을 다른 정점과 매칭시킬 수 있으면 성공. (dfs(against))
        if (against == -1 || !visited[against] && dfs(against)) {
            bookIsFrom[person] = book;
            personIsFrom[book] = person;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> num_books >> num_people;
        g = vvi(num_people);
        personIsFrom = vi(num_books, -1);
        bookIsFrom = vi(num_people, -1);
        RP(person, num_people) {
            int from, to;
            cin >> from >> to;
            for (int b = from - 1; b < to; b++) {
                g[person].push_back(b);
            }
        }

        int ans = 0;
        RP(person, num_people) {
            // 사람이 책에 매칭이 안되어 있다면? 매칭 안됬으면 매칭 시도.
            if (bookIsFrom[person] == -1) {
                visited = vb(num_people, false);
                if (dfs(person)) ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
