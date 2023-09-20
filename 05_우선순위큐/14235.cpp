#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t, a, p_value;
    priority_queue<int> present; // 선물 가치값 저장 우선순위 큐 선언

    // 입력
    cin >> t;
    while (t--) {
        cin >> a;
        // 선물을 충전한 경우
        if (a > 0) {
            while (a--) {
                // 충전 횟수만큼 큐에 저장
                cin >> p_value;
                present.push(p_value);
            }
        }
        // 아이들을 만난 경우
        else {
            // 선물이 남아 있는 경우, 가장 큰 값 출력
            if (!present.empty()) {
                cout << present.top() << "\n";
                present.pop();
            } else {
                // 선물이 남아있지 않은 경우 -1 출력
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}