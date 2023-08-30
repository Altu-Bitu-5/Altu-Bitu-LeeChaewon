#include <iostream>
#include <stack>
#include <string>

using namespace std;

void checkBracket(const string &sentence) {
    stack<char> s; // 괄호 저장 스택 선언

    for (int i = 0; i < sentence.size(); i++) {
        // 왼쪽 괄호인 경우 스택에 추가
        if (sentence[i] == '(' || sentence[i] == '[') {
            s.push(sentence[i]);
            // 오른쪽 괄호 ) 인 경우 (가 스택에 있는 경우만 pop, 아니면 push
        } else if (sentence[i] == ')') {
            if (s.empty() || s.top() != '(') {
                s.push(sentence[i]);
                break;
            }
            s.pop();
            // 오른쪽 괄호 ] 인 경우 [가 스택에 있는 경우만 pop, 아니면 push
        } else if (sentence[i] == ']') {
            if (s.empty() || s.top() != '[') {
                s.push(sentence[i]);
                break;
            }
            s.pop();
        }
    }
    // 스택이 비어있을 때만 yes 출력
    if (s.empty()) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    string sentence;
    while (true) {
        // 입력
        getline(cin, sentence);
        if (sentence == ".") {
            break;
        }
        // 빈 문장이 아닐 때만 괄호 검사 함수 호출
        if (!sentence.empty()) {
            checkBracket(sentence);
        }
    }
    return 0;
}
