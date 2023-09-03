#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q; // 순열 저장 큐 선언

    // 큐 채우기
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << "<";
    while (n--) {
        // 큐의 k번째까지 순회하며 pop & push, k번째 원소인 경우 출력
        for (int i = 1; i <= k; i++) {
            if (i == k) {
                cout << q.front();
                q.size() != 1 ? cout << ", " : cout << ">";
            } else {
                q.push(q.front());
            }
            q.pop();
        }
    }

    return 0;
}