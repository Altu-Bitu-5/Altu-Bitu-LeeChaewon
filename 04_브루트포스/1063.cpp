#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

struct Loc {
    char row;
    int col;
};
bool isValid(char row, int col) {
    if (row >= 'A' && row <= 'H' && col >= 1 && col <= 8) {
        return true;
    } else {
        return false;
    }
}
int main() {
    map<string, pair<int, int>> moves = {
        {"R", {0, 1}},  {"L", {0, -1}},  {"B", {-1, 0}},  {"T", {1, 0}},
        {"RT", {1, 1}}, {"LT", {1, -1}}, {"RB", {-1, 1}}, {"LB", {-1, -1}}};
    // 각 이동별 {행,열} 변경값 저장 map 선언
    string move, input_k, input_s; // 입력값 저장 string 선언
    int t;
    struct Loc king, stone;

    // 입력
    cin >> input_k >> input_s >> t;

    // 각 좌표 저장
    king.row = input_k[0];
    king.col = input_k[1] - '0';
    stone.row = input_s[0];
    stone.col = input_s[1] - '0';

    while (t--) {
        cin >> move;
        // 킹 이동 예상 값 저장
        char row_move = king.row + moves[move].second;
        int col_move = king.col + moves[move].first;

        // 킹 위치와 돌 위치가 같을 때 처리
        if (row_move == stone.row && col_move == stone.col) {
            // 돌 이동 예상값이 유효한 경우 이동
            if (isValid(char(stone.row + moves[move].second),
                        stone.col + moves[move].first)) {
                stone.row = char(stone.row + moves[move].second);
                stone.col += moves[move].first;
            } else {
                continue;
            }
        }
        if (isValid(char(row_move), col_move)) {
            king.row = char(king.row + moves[move].second);
            king.col += moves[move].first;
        }
    }
    cout << king.row << king.col << "\n" << stone.row << stone.col;
    return 0;
}