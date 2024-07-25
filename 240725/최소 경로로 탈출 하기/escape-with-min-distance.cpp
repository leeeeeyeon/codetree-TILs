#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_SIZE 100

using namespace std;

int board[MAX_SIZE][MAX_SIZE];
int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            // Index out of range
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            // 뱀이 있는 칸
            if (board[nx][ny] == 0) continue;
            // 이미 방문한 칸
            if (board[nx][ny] > 1) continue;

            board[nx][ny] = board[cx][cy]+1;

            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // (0, 0)에서 시작 (n-1, m-1)에 도착했을 때의 최단 거리
    // 현재 칸을 최단 거리로 갱신하는 방법으로 board 갱신
    // visited 배열 대신 현재 칸이 1보다 큰지 확인
    bfs(0, 0);

    if (board[n-1][m-1] == 1) cout << -1;
    else cout << board[n-1][m-1] - 1;
    return 0;
}