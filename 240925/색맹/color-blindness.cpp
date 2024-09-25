#include <iostream>
#include <queue>

#define MAX_N 100

using namespace std;

typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(vvc board) {
    int cnt = 0;

    int n = board.size();
    vvb visited = vvb(n, vector<bool>(n, false));

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;

            q.push({i, j});
            visited[i][j] = true;

            while(!q.empty()) {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (visited[nx][ny]) continue;

                    if (board[nx][ny] == board[cx][cy]) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }

            cnt++;
        }
    }

    return cnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vvc normalBoard = vvc(n, vector<char>(n, ' '));
    vvc colorBlindBoard = vvc(n, vector<char>(n, ' '));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char color;
            cin >> color;

            normalBoard[i][j] = color;
            if (color == 'G') colorBlindBoard[i][j] ='R';
            else colorBlindBoard[i][j] = color;
        }
    }

    // 적록색약 > R과 G를 동일하게 봄
    int normalCnt = bfs(normalBoard); // 적록색맹이 없는 사람이 봤을 때의 구역 수
    int colorBlindCnt = bfs(colorBlindBoard); // 적록색맹이 있는 사람이 봤을 때의 구역 수

    cout << normalCnt << ' ' << colorBlindCnt;

    return 0;
}