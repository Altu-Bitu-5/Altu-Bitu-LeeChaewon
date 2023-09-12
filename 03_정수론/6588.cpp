#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
vector<int> getPrime() {
    vector<int> is_prime(MAX + 1, 1); // 홀수 소수 여부 저장 벡터

    for (int i = 2; i * i <= MAX; i++) {
        if (!is_prime[i]) { // 이미 지워진 수면 탐색 X
            continue;
        }
        for (int j = i * i; j <= MAX; j += i) {
            if (is_prime[j]) { // 소수의 배수 지우기
                is_prime[j] = 0;
            }
        }
    }
    return is_prime;
}
int findConjecture(int n, vector<int> &is_prime) {
    // 두 소수의 차가 큰 경우가 우선이므로, 홀수 소수 중 큰 수부터 탐색
    for (int i = n; i > 2; i--) {
        // n보다 작은 소수의 합으로 표현 할 수 있는 경우 출력
        if (is_prime[i] && is_prime[n - i] && n - i != 1) {
            cout << n << " = " << n - i << " + " << i << "\n";
            return 0;
        }
    }
    return -1;
}
int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> is_prime = getPrime(); // 소수 구하기
    while (true) {
        int num;
        cin >> num;
        if (!num) { // 0이 입력되면 종료
            break;
        }
        if (findConjecture(num, is_prime) == -1) { // 골든바흐 추측 구하기
            cout << "Goldbach's conjecture is wrong.\n"; // 예외 처리
        }
    }

    return 0;
}