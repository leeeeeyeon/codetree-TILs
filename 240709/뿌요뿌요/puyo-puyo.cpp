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

    int n;
    cin >> n;

    vvi board = vvi(n, vector<int>(n, 0));
    vvb visited = vvb(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int block = 0; // 터지게 되는 블럭의 수
    int mx = 0; // 최대 블럭의 크기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;

            stack<pair<int, int>> s;
            int cnt = 1; // 만들어지는 블럭의 크기
            s.push({i, j});
            visited[i][j] = true;

            while(!s.empty()) {
                int cx = s.top().first;
                int cy = s.top().second;
                s.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];

                    // Index out of range
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    // 이미 방문한 경우
                    if (visited[nx][ny]) continue;
                    // 같은 숫자가 아닐 경우
                    if (board[cx][cy] != board[nx][ny]) continue;

                    s.push({nx, ny});
                    visited[nx][ny] = true;
                    cnt++;
                }
            }

            if (cnt >= 4) block++;
            if (cnt > mx) mx = cnt;
        }
    }

    cout << block << ' ' << mx;
    return 0;
}