#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int w0, i0, t, i, d, a;
    // 다이어트 전 체중, 다이어트 전 기초대사량, 역치
    cin >> w0 >> i0 >> t;
    // 다이어트 기간, 일일 섭취량, 활동 대사량
    cin >> d >> i >> a;

    int w1 = w0, w2 = w0; // 다이어트 후 체중
    int i1 = i0;          // 다이어트 중 변하는 기초대사량

    // 기초대사량 변화 무시
    w1 = w0 + d * (i - (i0 + a));
    if (w1 <= 0)
        cout << "Danger Diet\n";
    else
        cout << w1 << " " << i0 << "\n";

    // 기초대사량 변화 고려
    for (int j = 0; j < d; j++) {
        w2 += (i - (i1 + a));
        if (abs(i - (i1 + a)) > t)
            i1 += floor((i - (i1 + a)) / 2);
    }
    if (w2 <= 0 || i1 <= 0)
        cout << "Danger Diet\n";
    else {
        cout << w2 << " " << i1 << " ";
        if ((i0 - i1) > 0)
            cout << "YOYO";
        else
            cout << "NO";
    }
    return 0;
}