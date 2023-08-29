#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(string a, string b) {
    int sum_a = 0, sum_b = 0;

    // 길이 비교 정렬
    if (a.length() != b.length())
        return a.length() < b.length();
    // 자리 수 합 비교 정렬
    else {
        // 자리 수 합 구하기
        for (int i = 0; i < a.length(); i++) {
            // ascii 값으로 숫자 범위일 때만 더하기
            if (int(a[i]) - '0' < 10)
                sum_a += int(a[i]) - '0';
            if (int(b[i] - '0' < 10))
                sum_b += int(b[i]) - '0';
        }
        if (sum_a != sum_b)
            return sum_a < sum_b;
        // 사전 정렬
        else {
            return a < b;
        }
    }
}
int main() {
    int t;
    cin >> t;
    vector<int> serial_num(t);

    // 입력
    for (int i = 0; i < t; i++) {
        cin >> serial_num[i];
    }
    // 정렬
    sort(serial_num.begin(), serial_num.end(), compare);

    // 출력
    for (int i = 0; i < t; i++) {
        cout << serial_num[i] << "\n";
    }
    return 0;
}