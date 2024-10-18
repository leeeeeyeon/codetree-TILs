#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vvi board = vvi(n, vector<int>(n, 0));
    vpii point = vpii(n*n+1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            point[board[i][j]] = {i, j};
        }
    }

    while (m--) {
        // 숫자 1이 적힌 위치에서부터 숫자 n * n이 적힌 위치까지 반복
        for (int i = 1; i <= n*n; i++) {
            int cx = point[i].first;
            int cy = point[i].second;
            int mx = 0;
            // 인접한 여덟 방향 탐색
            for (int k = 0; k < 8; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                mx = max(mx, board[nx][ny]);
            }

            swap(board[cx][cy], board[point[mx].first][point[mx].second]);
            swap(point[i], point[mx]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}