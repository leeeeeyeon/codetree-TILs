#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> village;
int cnt;

void dfs(int cx, int cy, vvi &board, vvb &visited) {
    int n = board.size();

    for (int i = 0; i < 4; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        // Index out of range
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        // 벽이 놓인 칸인 경우
        if (board[nx][ny] == 0) continue;
        // 이미 방문한 칸인 경우
        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        cnt++;
        dfs(nx, ny, board, visited);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vvi board = vvi(n, vector<int>(n, 0));
    vvb visited = vvb(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 벽이 놓인 칸인 경우
            if (board[i][j] == 0) continue;
            // 이미 방문한 칸인 경우
            if (visited[i][j]) continue;

            cnt = 1;
            visited[i][j] = true;
            dfs(i, j, board, visited);

            village.push_back(cnt);
        }
    }
    sort(village.begin(), village.end());

    cout << village.size() << '\n';
    for (int elem : village) cout << elem << '\n';

    return 0;
}