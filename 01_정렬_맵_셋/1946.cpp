#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Score {
    int document, interview;
};

bool compare(Score &applicants1, Score &applicants2) {
    return applicants1.document < applicants2.document;
}

void addAccepted(int n, Score *applicants, vector<int> &accepted) {
    // 서류점수 1등 지원자를 합격자에 추가
    int counts = 1; // 합격자 수
    accepted[0] = applicants[0].interview;

    for (int j = 1; j < n; j++) {
        // 최신 합격자의 서류 순위보다 높은 경우 합격자에 추가
        if (applicants[j].interview < accepted[counts - 1]) {
            accepted[counts] = applicants[j].interview;
            counts++;
        }
    }
    cout << counts << "\n";
}

int main() {
    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        struct Score applicants[n]; // 지원자 서류, 인터뷰 점수 구조체 배열
        vector<int> accepted(n); // 합격자 인터뷰 점수 저장

        for (int j = 0; j < n; j++) {
            cin >> applicants[j].document >> applicants[j].interview;
        }

        // 서류 점수로 정렬
        sort(applicants, applicants + n, compare);

        // 정렬된 점수로 합격자 뽑기
        addAccepted(n, applicants, accepted);
    }
    return 0;
}
