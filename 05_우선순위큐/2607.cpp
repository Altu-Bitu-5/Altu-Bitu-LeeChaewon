#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int check_word(int *first_alpha, string &word, int first_len) {
    int diff = 0;
    int alpha[26] = {
        0,
    }; // 입력 단어 알파벳 개수 저장 정수 배열 선언

    // 입력 단어의 알파벳 개수 저장
    for (auto &i : word) {
        alpha[i - 'A']++;
    }

    // 알파벳 개수 차이 저장
    for (int i = 0; i < 26; i++) {
        diff += abs(alpha[i] - first_alpha[i]);
    }

    // 알파벳 개수 차이가 2 이하이고, 전체 길이 차이가 1 이하일 때 비슷한 값
    if (diff <= 2 && abs(long(first_len - word.length())) <= 1) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    int t, result = 0;
    string first_word, word;
    int first_alpha[26] = {
        0,
    }; // 첫번쨰 단어의 알파벳 개수 저장 정수 배열

    cin >> t;
    cin >> first_word;

    // 첫번째 단어의 알파벳 개수 저장
    for (auto &i : first_word) {
        first_alpha[i - 'A']++;
    }
    // 입력
    for (int i = 1; i < t; i++) {
        cin >> word;
        // 입력 문자열을 정렬
        sort(word.begin(), word.end());
        // 비슷한 문자열 갯수 구하기 함수 호출
        result += check_word(first_alpha, word, first_word.length());
    }

    cout << result;

    return 0;
}
