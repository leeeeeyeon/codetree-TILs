#include <iostream>

#define MAX_N 100

using namespace std;

int board[MAX_N][MAX_N];
int n, m, k;

// i번째 행에서 k~k+m-1번째 원소가 모두 0이면 true
bool isFit(int i, int k, int m) {
    for (int j = k; j < k+m; j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    k--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int lastRow = -1;
    // 첫 번째 행부터 시작해서 한 행씩 탐색
    for (int i = 0; i < n; i++) {
        // 만약 이번 행에서 k~k+m-1번째 열이 모두 0이면 다음 행 탐색
        // k~k+m-1번째 열 중 0이 아닌 값이 있으면 탐색 중단
        if (isFit(i, k, m)) lastRow = i;
        else break;
    }

    // 직전 행에서 k~k+m-1번째 열을 1로 바꾼 값이 정답
    if (lastRow >= 0) {
        for (int j = k; j < k+m; j++) {
            board[lastRow][j] = 1;
        }
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}