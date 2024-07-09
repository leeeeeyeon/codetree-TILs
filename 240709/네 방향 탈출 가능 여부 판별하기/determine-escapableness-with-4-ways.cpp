#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 뱀이 없는 경우 1, 뱀이 있는 경우 0
    vvi board = vvi(n, vector<int>(m, 0));
    vvb visited = vvb(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int canExit = 0; // 탈출 가능 여부
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 우측 하단까지 도착
        if (cx == n-1 && cy == m-1) {
            canExit = 1;
            break;
        }

        // BFS
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] != 1) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    cout << canExit;

    return 0;
}