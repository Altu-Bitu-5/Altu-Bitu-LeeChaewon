#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getGcd(int a, int b) {
    while (b) { // b==0 이면 a가 b의 최대 공약수
        a %= b;
        swap(a, b); // a > b 이여야하므로 a(a%b한 결과값)과 b 자리 바꿈
    }
    return a;
}
void find_fraction(vector<int> &numers, vector<int> &denoms) {
    // 분자, 분모의 합 구하기
    int numer = numers[0] * denoms[1] + numers[1] * denoms[0];
    int denom = denoms[0] * denoms[1];
    // 분자, 분모의 최대 공약수 구하기
    int gcd = getGcd(max(numer, denom), min(numer, denom));
    // 최대 공약수로 나눠 기약 분수 구하기
    cout << numer / gcd << " " << denom / gcd;
}

int main() {
    vector<int> numers(2), denoms(2); // 분자, 분모 저장 벡터 선언

    // 입력
    for (int i = 0; i < 2; i++) {
        cin >> numers[i] >> denoms[i];
    }

    // 기약 분수 구하기
    find_fraction(numers, denoms);

    return 0;
}