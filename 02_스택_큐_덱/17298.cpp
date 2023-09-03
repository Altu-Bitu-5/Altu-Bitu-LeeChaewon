#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void find_nge(int t, vector<int> &input_list) {
    vector<int> nge(t); // 오큰수 저장용 벡터 선언
    stack<int> s;

    for (int i = 0; i < t; i++) {
        // 오른쪽 > 왼쪽인 경우 nge에 추가, 왼쪽은(기존 값) 스택에서 삭제
        while (!s.empty() && input_list[s.top()] < input_list[i]) {
            nge[s.top()] = input_list[i];
            s.pop();
        }
        // 입력값이 아닌 input_list의 인덱스를 스택에 저장
        s.push(i);
    }
    // nge를 찾지 못한 스택에 남은 값(input_list의 인덱스)에는 -1 저장
    while (!s.empty()) {
        nge[s.top()] = -1;
        s.pop();
    }
    // 결과 출력
    for (auto &i : nge) {
        cout << i << " ";
    }
}
int main() {
    int t;
    cin >> t;

    vector<int> input_list(t);

    // 입력
    for (int i = 0; i < t; i++) {
        cin >> input_list[i];
    }

    find_nge(t, input_list);

    return 0;
}