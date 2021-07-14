//
// Created by 신승민 on 2021/07/13.
//

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list<B> Bs;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        Bs.emplace_back(i, temp);
    }

    for (auto it = Bs.begin(); !Bs.empty();) {
        int name = it->first;
        int move = it->second;
        if (move > 0) move--;

        cout << name << " ";

        it = Bs.erase(it);
        if (it == Bs.end()) it++;

        for (int ward = 0; ward < abs(move); ward++) {
            if (move > 0) {
                it++;
                if (it == Bs.end()) it++;
            } else {
                it--;
                if (it == Bs.end()) it--;
            }
        }
    }
    cout << endl;

    return 0;
}
