#include <functional>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t, num;
    priority_queue<int, vector<int>, greater<int>>
        answer; // 오름차순으로 저장하는 우선 순위 큐
    cin >> t;

    // 입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // N X N 입력 받기
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            cin >> num;
            answer.push(num);
            // t번째로 큰 수까지만 저장
            if (answer.size() > t)
                answer.pop();
        }
    }
    // 오름차순으로 입력했으므로 top값 (t번째로 큰 수) 반환
    cout << answer.top();

    return 0;
}