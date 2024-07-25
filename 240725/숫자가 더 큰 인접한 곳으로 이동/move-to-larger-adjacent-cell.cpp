#include <iostream>

#define MAX_N 100
using namespace std;

int board[MAX_N][MAX_N];
int n, cx, cy;

// 상하좌우 순서로
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool canMove(int cx, int cy) {
    bool flag = false; // 인접한 네 칸 중 이동할 칸이 있는지?

    for(int k = 0; k < 4; k++) {
        int nx = cx + dx[k];
        int ny = cy + dy[k];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (board[nx][ny] > board[cx][cy]) flag = true;
    }

    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> cx >> cy;
    cx--;
    cy--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    do {
        cout << board[cx][cy] << ' ';

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] > board[cx][cy]) {
                cx = nx;
                cy = ny;
                break;
            }
        }
    } while (canMove(cx, cy));

    // 마지막으로 방문한 원소
    cout << board[cx][cy];

    return 0;
}