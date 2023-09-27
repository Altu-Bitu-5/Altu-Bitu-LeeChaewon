#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void makePalindrome(string &sorted_name) {
    stack<char> s; // 팰린드롬 알파벳 개수 짝 맞추기용 스택 선언
    vector<char> palind_name; // 팰린드롬 저장용 벡터 선언

    // 알파벳 개수 짝 맞추기
    for (auto &i : sorted_name) {
        if (s.empty()) {
            s.push(i);
        } else {
            // 입력 값이 스택 top값과 같으면 pop하고 팰린드롬에 추가
            if (s.top() == i) {
                s.pop();
                palind_name.push_back(i);
            } else {
                s.push(i);
            }
        }
    }
    // 팰린드롬 O
    if (s.size() <= 1) {
        // 앞 부분 출력
        for (auto &i : palind_name) {
            cout << i;
        }
        // 길이가 홀수인 경우 스택에 남은 중간 부분 출력
        if (!s.empty()) {
            cout << s.top();
        }
        // 뒷 부분 출력 (앞 부분 역순)
        reverse(palind_name.begin(), palind_name.end());
        for (auto &i : palind_name) {
            cout << i;
        }
    }
    // 팰린드롬 X
    else {
        cout << "I'm Sorry Hansoo";
    }
}
int main() {
    string input_name; // 입력값 저장

    // 입력
    cin >> input_name;

    // 입력값 정렬
    sort(input_name.begin(), input_name.end());

    makePalindrome(input_name);
    return 0;
}