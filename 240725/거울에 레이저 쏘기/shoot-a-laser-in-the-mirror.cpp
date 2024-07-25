#include <iostream>
#include <algorithm>

#define MAX_SIZE 1'000

using namespace std;

int n, m;
char board[MAX_SIZE+1][MAX_SIZE+1];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int countReflect(int cx, int cy) {
    int cnt = 0;
    int dir = 0; // 레이저의 방향 초기화

    // 시작 방향을 정해야 해
    if (cx == 0) dir = 0;
    else if (cy == m+1) dir = 1;
    else if (cx == n+1) dir = 2;
    else dir = 3;
    
    // 격자 내부로 진입
    cx += dx[dir];
    cy += dy[dir];

    // 현재 좌표 중 하나가 0 또는 n+1 또는 m+1일 때까지
    while(cx > 0 && cy > 0 && cx <= n && cy <= m) {
        // 만약 거울이 '/'라면
        if (board[cx][cy] == '/') {
            // 레이저 방향 바꾸고
            if (dir == 0) dir = 1;
            else if (dir == 1) dir = 0;
            else if (dir == 2) dir = 3;
            else dir = 2;

            // 칸 이동
            cnt++;
            cx += dx[dir];
            cy += dy[dir];
        } else {
            // 만약 거울이 '\'라면
            // '\'는 이스케이프 문자라서 '\\'로 써야 함
            // 레이저 방향 바꾸고
            if (dir == 0) dir = 3;
            else if (dir == 1) dir = 2;
            else if (dir == 2) dir = 1;
            else dir = 0;
            
            // 칸 이동
            cnt++;
            cx += dx[dir];
            cy += dy[dir];
        }

    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    int mx = 0;
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= m+1; j++) {
            // 가장자리가 아니면 시작점이 될 수 없음
            if (i >= 1 && i <= n && j >= 1 && j <= m) continue;

            // 꼭지점은 시작점이 될 수 없음
            bool topPoint = (i == 0 && j == 0) || (i == 0 && j == m+1);
            bool bottomPoint = (i == n+1 && j == 0) || (i == n+1 && j == m+1);
            if (topPoint || bottomPoint) continue;

            mx = max(mx, countReflect(i, j));
        }
    }

    cout << mx;

    return 0;
}