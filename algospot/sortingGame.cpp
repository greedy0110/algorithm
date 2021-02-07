// 시간 복잡도에 TestCase 의 갯수도 포함해야 한다.
// 문제를 간략화 할 필요가 있다.

// 문제 스케일을 줄일 수 있나?

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef vector<int> vi;

int C, n;

class Node {
public:
    vi value;
    int distance;

    // O(n^2)
    vector<Node> getNodesNextTo() {
        vector<Node> nexts;

        for (int i = 0; i< value.size(); i++) {
            for (int j = i+1; j < value.size(); j++) {
                vi nextValue;
                // i-1 까지 그냥 담고
                // [i,j] 영역은 거꾸로 담고
                // j+1 부터는 그냥 담는다.
                for (int k = 0; k < i; k++) {
                    // 0..i-1
                    nextValue.push_back(value[k]);
                }

                for (int k = j; k >= i; k--) {
                    // j..i
                    nextValue.push_back(value[k]);
                }

                for (int k = j + 1; k < value.size(); k++) {
                    // j+1..end
                    nextValue.push_back(value[k]);
                }

                Node next;
                next.distance = this->distance + 1;
                next.value = nextValue;

                nexts.push_back(next);
            }
        }

        return nexts;
    }

    // O(n)
    bool isSorted() const {
        bool ret = true;
        int prev = value[0];
        for (auto it = value.cbegin() + 1; it != value.cend(); it++) {
            // 같은 수는 없다고 가정한다.
            if (prev > *it) {
                ret = false;
                break;
            }
            prev = *it;
        }
        return ret;
    }
};

map<vi, bool> discovered;
vector<map<vi, int>> cache = vector<map<vi, int>>(9);

void makeCache(int n) {
    discovered.clear();
    vi value ;
    
    for (int i=0; i<n;i++) { value.push_back(i); }

    queue<Node> q;

    Node node;
    node.value = value;
    node.distance = 0;

    q.push(node);
    discovered[node.value]= true;

    while (!q.empty()) { // V 만큼 반복 O(N!*N^2*logN!) = 
        Node cur = q.front();
        q.pop();

        cache[n][cur.value] = cur.distance;

        vector<Node> nexts = cur.getNodesNextTo(); // O(N^2)
        for (auto next: nexts) { // E 반복, O(E*logV)
            // 이미 queue에 들어간 적이 있는 케이스는 무시하자.
            if (discovered.find(next.value) != discovered.end()) continue; // O(logV)

            discovered[next.value]= true; // O(logV)
            q.push(next);
        }
    }
}

vi normalize(vi list) {
    vi ret;
    for (int i=0; i<list.size(); i++) {
        int order = 0;
        for (int j = 0; j<list.size(); j++) {
            if (list[i] > list[j]) {
                order++;
            }
        }
        ret.push_back(order);
    }
    return ret;
}

// 가능한 정점의 갯수: 입력으로 주어지는 배열을 마구잡이로 재배열한 게 가능한 정점이므로 8! ~= 40000 => n!
// 가능한 간선의 갯수: 입력으로 주어지는 배열중 임이의 2 위치를 골라서 다음 노드를 만들 수 있으므로 8C2 == 28 => n^2
// BFS에서 시간 복잡도: 
int main() {
    cin >> C;

    for (int i=1; i<=8;i++) makeCache(i);

    while (C--) {
        cin >> n;
        vi value = vi(n);

        for (int i = 0; i < n; i++) {
            cin >> value[i];
        }

        cout << cache[n][normalize(value)] << endl;
    }

    return 0;
}
