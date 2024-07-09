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

    int n, k; // 격자의 크기, 시작점의 수
    cin >> n >> k;

    // 0: 이동할 수 있음, 1: 이동할 수 없음
    vvi board = vvi(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    vector<pair<int, int>> starts;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        // 좌표가 (1,1)부터 시작
        starts.push_back({x-1, y-1});
    }

    int cnt = 0; // 시작지점으로부터 방문이 가능한 서로 다른 칸의 수
    vvb visited = vvb(n, vector<bool>(n, false));
    for (auto start : starts) {
        if (visited[start.first][start.second]) continue;

        queue<pair<int, int>> q;
        q.push({start.first, start.second});
        visited[start.first][start.second] = true;
        cnt++;

        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (visited[nx][ny]) continue;
                if (board[nx][ny] == 1) continue;

                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}