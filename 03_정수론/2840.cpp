#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ic; // int, char 쌍 형식 선언
const int ALPHA = 26;       // 알파벳 체크 벡터 크기용 상수 선언

// index부터 시계방향으로 바퀴에 적어놓은 알파벳 출력
string printWheel(int n, int index, vector<char> &wheel) {
    string ans = ""; // 바퀴에 적은 알파벳 임시 저장 문자열
    // 마지막 입력 받은 알파벳부터, 역순으로 출력
    for (int i = index + n; i > index; i--) {
        ans += wheel[i % n]; // index 2 1 0 8 7 6 5 4 이런식으로 index 변화
    }
    return ans; // 알파벳 리턴
}

// 행운의 바퀴 반환
string makeWheel(int n, int k, vector<ic> &record) {
    vector<char> wheel(n, '?'); // 바퀴의 모든 알파벳을 ?로 초기화
    vector<bool> is_available(
        ALPHA, false); // AtoZ 까지 알파벳이 들어왔는지 체크하는 벡터

    int index = 0; // 화살표가 가리키는 인덱스

    for (int i = 0; i < k; i++) {
        int s = record[i].first; // 화살표가 가리키는 글자가 변하는 횟수
        char ch = record[i].second; // 회전을 멈추었을 때 가리키던 글자

        index = (index + s) % n; // 회전한 후 화살표가 가리키는 인덱스, 바퀴 칸
                                 // 수가 n이므로 그 이하로 유지

        // 해당 칸이 ch로 이미 채워져 있는 경우 넘어감
        if (wheel[index] == ch) {
            continue;
        }

        // 다른 글자로 채워져있거나 해당 글자가 이미 사용된 알파벳인 경우 ! 반환
        if (wheel[index] != '?' || is_available[ch - 'A']) {
            return "!";
        }

        wheel[index] = ch; // 해당 칸에 글자 적기
        is_available[ch - 'A'] =
            true; // 해당 알파벳이 사용되었으므로 true로 변경
    }
    return printWheel(n, index, wheel); // 알파벳 출력 함수 호출
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n, k;
    cin >> n >> k; // 바퀴 크기, 회전 횟수 입력

    vector<ic> record(k); // int, char 쌍으로 record 벡터 선언
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >>
            record[i].second; // 알파벳 변경 횟수, 알파벳 입력
    }

    // 연산 & 출력
    cout << makeWheel(n, k, record);

    return 0;
}
