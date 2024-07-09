#include <iostream>
#include <vector>
#include <stack>

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

    vvi board = vvi(n, vector<int>(m, 0));
    int mx = 0; // 마을에서 가장 높은 집
    pair<int, int> ret = {1, 0}; // {k, 안전 영역의 수}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] > mx) mx = board[i][j];
        }
    }

    // 1부터 k까지 반복하면서 ...
    // DFS를 통해 board[cx][cy]가 k보다 큰 칸을 구해
    // (0,0)부터 (n-1, m-1)까지 돌면서 그 지점을 시작점으로 해서 영역을 구해
    // 현재 지점이 이미 방문했다면 continue
    for (int k = 1; k < mx; k++) {
        vvb visited = vvb(n, vector<bool>(m, false));
        int area = 0;
        // DFS (with stack)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 이미 방문했다면 continue
                if (visited[i][j]) continue;
                // 현재 칸이 안전하지 않은 경우
                if (board[i][j] <= k) continue;

                stack<pair<int, int>> s;
                s.push({i, j});
                visited[i][j] = true;

                while(!s.empty()) {
                    int cx = s.top().first;
                    int cy = s.top().second;
                    s.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = cx + dx[d];
                        int ny = cy + dy[d];

                        // Index out of range
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        // 이미 방문한 칸
                        if (visited[nx][ny]) continue;
                        // 안전하지 않은 높이
                        if (board[nx][ny] <= k) continue;

                        s.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }

                area++;
            }
        }
        if (area > ret.second) ret = {k, area};
    }

    cout << ret.first << ' ' << ret.second;
    return 0;
}