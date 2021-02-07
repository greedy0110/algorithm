#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    int position;
    int distance;
};

typedef queue<Node> qn;
typedef vector<bool> vb;

int N, K;
vb discovered;

int main() {
    cin >> N >> K;

    int answer = 0;
    if (K <= N) {
        // 뒤에 있는 경우 순간이동 능력이 무쓸모다.
        answer = N - K;
    }
    else {
        if (N == 0) {
            N++;
            answer++;
        }

        // 이 이상은 시작 점부터 걸어가는 것과 동치이므로 무시 가능하다.
        int threshold = min(100000, 2*K - N);
        discovered = vector<bool>(threshold + 1, false);

        qn queue;

        int startPoint = N;
        while (startPoint <= threshold) {
            Node n;
            n.distance = 0;
            n.position = startPoint;

            discovered[startPoint] = true;
            queue.push(n);
            startPoint *= 2;
        }

        while (!queue.empty()) {
            Node cur = queue.front();
            queue.pop();

            if (cur.position == K) {
                answer += cur.distance;
                break;
            }

            int startPoint = cur.position + 1;
            while (startPoint <= threshold) {
                if (discovered[startPoint]) {
                    startPoint *= 2;
                    continue;
                }

                Node n;
                n.distance = cur.distance + 1;
                n.position = startPoint;

                discovered[startPoint] = true;
                queue.push(n);
                startPoint *= 2;
            }

            startPoint = cur.position - 1;
            while (startPoint != 0 && startPoint <= threshold) {
                if (discovered[startPoint]) {
                    startPoint *= 2;
                    continue;
                }

                Node n;
                n.distance = cur.distance + 1;
                n.position = startPoint;

                discovered[startPoint] = true;
                queue.push(n);
                startPoint *= 2;
            }
        }
    }

    cout << answer << endl;
    return 0;
}
