#include <iostream>

#define MAX_N 100

using namespace std;

char board[MAX_N][MAX_N];
int n, sx, sy;
int cx, cy, nx, ny;
int rx, ry; // nx, ny의 오른쪽 칸
int dir = 0;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool canMove(int i, int j) {
    bool flag = false;

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dx[k];

        if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
        if (board[ni][nj] != '#') flag = true;
    }

    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> sx >> sy;

    cx = --sx;
    cy = --sy;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int t = 0;
    bool canExit = true;
    while(true) {
        // 시간초과 반례: 벽으로 둘러쌓인 경우
        if(!canMove(cx, cy)) {
            cout << cx << ' ' << cy << endl;
            canExit = false;
            break;
        }

        // nx, ny를 구해
        nx = cx + dx[dir];
        ny = cy + dy[dir];

        // 바라보고 있는 방향으로 이동 불가능 > 반시계 방향 회전
        // 시간 소요 X
        if (board[nx][ny] == '#') {
            dir = (dir+1) % 4;
            continue;
        }

        // 바라보고 있는 방향으로 이동 가능
        // 격자 밖이라면 break
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
            t++;
            break;
        }

        // nx, ny의 오른쪽 칸을 구해
        int tempDir = dir;
        if (dir == 0) tempDir = 3;
        else tempDir--;
        
        rx = nx + dx[tempDir];
        ry = ny + dy[tempDir];

        // rx, ry에 벽 있으면 직진
        if (board[rx][ry] == '#') {
            cx = nx;
            cy = ny;

            t++;
        } else { // rx, ry에 벽 없으면 시계 방향 회전 후 직진
            // 한 칸 전진 > 회전 > 한 칸 더 전진
            if (dir == 0) dir = 3;
            else dir--;

            cx = nx + dx[dir];
            cy = ny + dy[dir];

            // 시간 증가
            t += 2;
        }

        // 미로 탈출 불가능 == 원점으로 돌아왔을 때
        if (cx == sx && cy == sy) {
            canExit = false;
            break;
        }
    }

    if (canExit) cout << t;
    else cout << -1;

    return 0;
}