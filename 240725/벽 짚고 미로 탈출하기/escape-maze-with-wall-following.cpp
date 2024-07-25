#include <iostream>

#define MAX_N 100
#define DIR_NUM 4
using namespace std;

char board[MAX_N][MAX_N];
int n;
int cx, cy, nx, ny;
int rx, ry; // nx, ny의 오른쪽 칸
int dir = 0;
bool visited[MAX_N][MAX_N][DIR_NUM];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool canMove(int i, int j) {
    bool flag = false;

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if (ni < 0 || nj < 0 || ni >= n || nj >= n) flag = true;
        if (board[ni][nj] != '#') flag = true;
    }

    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> cx >> cy;
    cx--;
    cy--;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int t = 0;
    bool canExit = true;
    while(true) {
        if (visited[cx][cy][dir]) {
            canExit = false;
            break;
        }

        visited[cx][cy][dir] = true;

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
    }

    if (canExit) cout << t;
    else cout << -1;

    return 0;
}