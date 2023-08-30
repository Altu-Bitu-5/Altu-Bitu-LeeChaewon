#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a, b;
    // 입력
    cin >> a >> b;

    // vector 동적 할당 크기 구하기
    int len = max(a.length(), b.length());

    vector<int> total(len +
                      1); // 각 자리수의 합 저장 벡터 선언 (+1은 제일 큰 자리수 올림 위해)

    // 각 자리수 덧셈
    for (int i = 0; i < a.length(); i++) {
        total[len - i] += a[a.length() - i - 1] - '0';
    }
    for (int i = 0; i < b.length(); i++) {
        total[len - i] += b[b.length() - i - 1] - '0';
    }
    // 각 자리수 올림, 나머지 처리
    for (int i = len; i > 0; i--) {
        if (total[i] >= 10) {
            total[i - 1] += total[i] / 10;
            total[i] %= 10;
        }
    }

    // 출력
    for (int i = (total[0] == 0); i <= len; i++) { // 첫 자리가 0인 경우 제외
        cout << total[i];
    }

    return 0;
}
