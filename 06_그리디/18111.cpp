#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii; // <int, int> pair 구조체 선언

const int MAX_HEIGHT = 257; // 256 + 1
const int INF = 987'654'321; // 가능한 최댓값이 12,800,000이므로 많이 쓰는
                             // 큰 수인 987654321을 사용

// 모든 땅의 높이를 height로 만드는 비용 계산
int calcCost(int height, int n, int m, int b, vector<vector<int>> &blocks) {
    int cost = 0;
    int added = 0;   // 추가해야 하는 블록의 총 개수
    int removed = 0; // 제거해야 하는 블록의 총 개수

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int gap =
                abs(height - blocks[i][j]); // 기준 높이 height와 다른 높이간의
                                            // 차이를 gap으로 저장

            if (blocks[i][j] > height) {
                // 목표 높이보다 높은 칸인 경우, gap개의 블록 제거
                removed += gap;
            } else if (blocks[i][j] < height) {
                // 목표 높이보다 낮은 칸인 경우, gap개의 블록 추가
                added += gap;
            }
        }
    }

    // 전체 비용 계산 (제거, 추가해야할 블록수 * 소요 시간)
    cost = 2 * removed + added;

    // 블록 개수가 부족하다면 모든 땅의 높이를 height로 만드는 것이 불가능,
    // 불가능한 경우 최대값을 리턴, 아니면 계산한 cost 리턴
    return (added > (b + removed)) ? INF : cost;
}

// 모든 땅의 높이를 같게 만드는 최소 비용과 그 때의 땅의 높이
pii makeGroundEven(int n, int m, int b, vector<vector<int>> &ground) {
    int minCost = INF; // 가장 큰 값으로 minCost 초기화
    int height = 0;

    // 모든 높이를 다 만들어보고 최소 비용 찾기
    for (int i = 0; i < MAX_HEIGHT; i++) { // 최대 높이인 256까지 기준 높이를 둠
        int cost = calcCost(
            i, n, m, b, ground); // 해당 높이로 땅을 고르기에 필요한 시간 계산
        if (cost <=
            minCost) { // minCost 보다 작으면 값 갱신 (땅 고르기 가능할 때)
            minCost = cost;
            height = i; // 그때 높이 (최종 높이) 저장
        }
    }

    return {minCost, height}; // 땅 고르기에 걸린 시간, 높이 반환를 pair로 반환
}

int main() {
    int n, m, b;

    // 입력
    cin >> n >> m >> b; // 세로, 가로, 인벤토리 수 입력 받음
    vector<vector<int>> ground(n, vector<int>(m)); // 2차원 벡터 선언
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { // n*m만큼 땅의 높이를 입력 받음
            cin >> ground[i][j];
        }
    }

    // 연산, 결과를 시간, 높이 pair로 받아서 저장
    pii answer = makeGroundEven(n, m, b, ground);

    // 출력, 시간, 높이 순서로 pair 출력
    cout << answer.first << " " << answer.second << "\n";

    return 0;
}