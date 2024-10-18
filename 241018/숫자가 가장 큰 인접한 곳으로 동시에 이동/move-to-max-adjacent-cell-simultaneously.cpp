#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;

// 상하좌우 순으로
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t; // 격자의 크기, 구슬의 개수, 시간
    cin >> n >> m >> t;

    vvi board = vvi(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    vvi count = vvi(n, vector<int>(n, 0));

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        count[x-1][y-1] = 1;
    }

    while(t--) {
        vvi newCount = vvi(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 진주가 있는 칸인 경우
                if (count[i][j] == 1) {
                    int nx = -1;
                    int ny = -1;
                    int mx = 0;
                    // 상하좌우 중 가장 큰 값이 적힌 위치를 찾는다
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if (x < 0 || y < 0 || x >= n || y >= n) continue;
                        if (board[x][y] > mx) {
                            nx = x;
                            ny = y;
                            mx = board[x][y];
                        }
                    }

                    newCount[nx][ny]++;
                }
            }
        }

        // newCount에서 2 이상인 값을 0으로 만든다
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (newCount[i][j] >= 2) newCount[i][j] = 0;
            }
        }

        // count에 복사
        count = newCount;
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (count[i][j] == 1) answer++;
        }
    }

    cout << answer;

    return 0;
}