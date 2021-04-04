#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> state_table[100][300];
int final_state;

string all_word ="1234567890qwertyuiopasdfghjkllzxcvbnmPOIUYTREWQLKJHGFDSAMNBVCXZ";
vector<char> anyword = vector<char>(all_word.begin(), all_word.end());

void printset(const set<int>& s) {
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;
}

void printtable() {
    for (int state = 0; state <= final_state; state++) {
        for (int i=0; i<300; i++) {
            auto next = state_table[state][i];
            if (!next.empty()) {
                cout << state << ", " << (char)i << endl; 
                printset(next);
            }
        }
    }
}

void make_state_machine(string regex) {
    // state 에서 input이 들어오면 어떤 state로 변하는 가를 정의
    int current_state = 0;
    int next_state;
    for (int i=0; i<regex.length(); i++) {
        switch(regex[i]) {
            case '*':
                // 자기 자신의 state로 이동 가능.
                for (auto it = anyword.begin(); it != anyword.end(); it++) {
                    state_table[current_state][*it].insert(current_state);
                }
                break;
            case '?':
                // 아무 거나 입력하면 다음 state로 이동 가능.
                next_state = ++current_state;
                for (auto it = anyword.begin(); it != anyword.end(); it++) {
                    state_table[current_state][*it].insert(next_state);
                }
                break;
            default:
                // 해당 글자를 눌러야 다음 state로 이동 가능.
                next_state = ++current_state;
                state_table[current_state][regex[i]].insert(next_state);
        }
    }

    final_state = current_state;
}

set<int> next_state(const set<int>& current_state, char token) {
    set<int> next;

    printset(current_state);
    for (auto it = current_state.cbegin(); it != current_state.cend(); it++) {
        auto next_state_part = state_table[*it][token];
        printset(next_state_part);
        next.insert(next_state_part.begin(), next_state_part.end());
    }

    return next;
}

bool match(string filename) {
    set<int> current_state;
    current_state.insert(0);

    cout << " " << filename << endl;
    for (int i=0; i<filename.length(); i++) {
        char token = filename[i];
        current_state = next_state(current_state, token);
    }

    return current_state.find(final_state) != current_state.end();
}

int main () {
    int C;
    cin >> C;

    while (C--) {
        string regex;
        cin >> regex;
        make_state_machine(regex);

        int num;
        cin >> num;
        vector<string> words;
        for (int i=0;i<num;i++) {
            string word; cin >> word; words.push_back(word);
        }

        vector<string> matched_words;
        for (auto it = words.cbegin(); it != words.cend(); it++) {
            if (match(*it)) {
                matched_words.push_back(*it);
            }
        }
        sort(matched_words.begin(), matched_words.end());

        for (auto it = matched_words.cbegin(); it != matched_words.cend(); it++) {
            cout << *it << endl;
        }
    }
    return 0;
}
