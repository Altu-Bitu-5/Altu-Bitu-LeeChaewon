#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long min_v;
    vector<long long> velocity;
    // 입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n;
    while (n--) {
        int v;
        cin >> v;
        velocity.push_back(v);
    }
    min_v = velocity.back(); // 가장 마지막 행성 속도 값 저장

    // 속도를 줄일 수 밖에 없으므로, 가장 마지막 행성부터 역으로 최솟값 갱신
    for (int i = velocity.size() - 2; i >= 0; i--) {
        if (min_v < velocity[i]) {
            min_v = velocity[i]; // 최솟값 갱신
            continue;
        }
        // 최솟값이 다음 행성 속도의 배수가 아닌 경우
        if (min_v % velocity[i] != 0) {
            min_v += velocity[i]; // 배수보다 더 큰 값이 되게 더 해줌
        }
        min_v = ((min_v / velocity[i])) *
                velocity[i]; // 다음 속도의 배수로 최솟값 갱신
    }
    cout << min_v;

    return 0;
}