#include <iostream>
#include <string>
using namespace std;

void getTitle(int n) {
    // 666부터 666포함 값 찾기
    for (int i = 666, count = 0;; i++) {
        //
        if (to_string(i).find("666") != string::npos) {
            count++;
            if (count == n) {
                cout << i;
                break;
            }
        }
    }
}
int main() {
    int n;
    //  입력
    cin >> n;

    // 영화 이름 구하기 함수 호출
    getTitle(n);
    return 0;
}