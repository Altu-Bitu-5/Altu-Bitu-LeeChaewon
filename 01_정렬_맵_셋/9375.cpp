#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int t, n;
    string cloth_name, cloth_category;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        map<string, int> clothes;
        // 입력
        for (int j = 0; j < n; j++) {
            cin >> cloth_name;
            cin >> cloth_category;
            // cloth_category 값이 있는 값이면 ++, 없으면 map에 추가
            if (clothes.find(cloth_category) != clothes.end())
                clothes[cloth_category] += 1;
            else
                clothes[cloth_category] = 1;
        }
        //  결과 출력
        int result = 1;
        // 옷 수 + 1을 곱해서 의상의 경우의 수 구하기
        for (auto &pair : clothes) {
            result *= (pair.second + 1);
        }
        // 아무것도 입지 않았을 때 제외
        result -= 1;
        cout << result << "\n";
    }
    return 0;
}