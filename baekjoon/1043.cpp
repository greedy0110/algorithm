#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<ll> vlli;

vi parent(51);
int N, M;

int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);

    parent[y] = x;
}

int main() {
    iota(parent.begin(), parent.end(), 0);

    cin >> N >> M;

    int k;
    cin >> k;
    if (k == 0) {
        cout << M << endl;
        return 0;
    }

    vi true_body = vi(k);

    cin >> true_body[0];
    for (int i = 1; i < k; i++) {
        cin >> true_body[i];
        uni(true_body[i - 1], true_body[i]);
    }

    vvi parties = vvi(M);

    for (int i = 0; i < M; i++) {
        int group;
        cin >> group;

        if (group == 0) {
            break;
        }

        vi party = vi(group);
        cin >> party[0];
        for (int j = 1; j < group; j++) {
            cin >> party[j];
            uni(party[j - 1], party[j]);
        }
        parties[i] = party;
    }

    si true_crew;
    for (int i = 0; i < k; i++) {
        true_crew.insert(true_body[i]);
        int true_head = find(true_body[i]);
        for (int j = 1; j <= N; j++) {
            if (find(j) == true_head) {
                true_crew.insert(j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        vi party = parties[i];
        bool lie_able = true;
        for (int &j : party) {
            if (true_crew.find(j) != true_crew.end()) {
                lie_able = false;
                break;
            }
        }
        if (lie_able) ans++;
    }

    cout << ans << endl;

    return 0;
}