#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    int count = 0;
    cin >> n >> m;

    vector<string> set(n), test(m);

    // 입력
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> test[i];
    }

    // 정렬
    sort(set.begin(), set.end());
    sort(test.begin(), test.end());

    // 탐색
    for (int i = 0; i < m; i++) {
        if (binary_search(set.begin(), set.end(), test[i])) {
            count++;
        }
    }
    // 출력
    cout << count;

    return 0;
}