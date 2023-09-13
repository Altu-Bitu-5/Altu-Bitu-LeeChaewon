#include <iostream>

using namespace std;

int calculator(int bit_mask, string &calc, int n) {
    bool isValid = (bit_mask & (1 << n)); // 원소 여부 저장
    // add: 원소 없으면 추가
    if (calc == "add" && !isValid) {
        bit_mask |= (1 << n);
    }
    // remove: 원소 있으면 삭제
    if (calc == "remove" && isValid) {
        bit_mask &= ~(1 << n);
    }
    // check: 원소 여부 출력
    if (calc == "check") {
        cout << isValid << "\n";
    }
    // toggle: 원소 있으면 삭제 / 없으면 추가
    if (calc == "toggle") {
        if (isValid) {
            bit_mask &= ~(1 << n);
        } else {
            bit_mask |= (1 << n);
        }
    }
    // all: 1~20 자리 1로 초기화
    if (calc == "all") {
        bit_mask = (1 << 21) - 1;
    }
    // empty: 공집합으로 초기화
    if (calc == "empty") {
        bit_mask = 0;
    }
    return bit_mask;
}
int main() {
    int t, num;
    string calc;      // 연산 종류 저장 string 선언
    int bit_mask = 0; // 각 자리 원소 여부 저장 int 선언

    // 입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> t;

    while (t--) {
        cin >> calc;
        if (calc != "all" && calc != "empty") {
            cin >> num;
        }
        // 연산 후 bit_mask 갱신
        bit_mask = calculator(bit_mask, calc, num);
    }

    return 0;
}