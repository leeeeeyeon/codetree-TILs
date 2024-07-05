#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

void dfs(int cx, int cy, vvi &board, vvb &visited) {
    int n = board.size();
    int m = board[0].size();
    
    // 재귀
    for (int i = 0; i < 2; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        // Index out of range
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        // 뱀이 위치한 칸인 경우
        if (board[nx][ny] == 0) continue;
        // 이미 방문한 칸인 경우
        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        dfs(nx, ny, board, visited);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vvi board = vvi(n, vector<int>(m, 0));
    vvb visited = vvb(n, vector<bool>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    visited[0][0] = true;
    dfs(0, 0, board, visited);

    int canExit = visited[n-1][m-1];
    cout << canExit;

    return 0;
}