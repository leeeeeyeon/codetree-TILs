#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;

    vvi board = vvi(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int cx, cy; // 폭탄이 터질 중심
    cin >> cx >> cy;
    // 인덱스 0부터 시작하는거 맞춰주기 위함
    cx--;
    cy--;

    int range = board[cx][cy]; // 폭탄이 터지는 범위
    // 폭탄이 터진다
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < range; j++) {
            int nx = cx + dx[i]*j;
            int ny = cy + dy[i]*j;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            board[nx][ny] = 0;
        }
    }
    
    // 중력이 작용한다
    for (int col = 0; col < n; col++) {
        vector<int> temp;
        for (int row = 0; row < n; row++) {
            if (board[row][col] != 0) temp.push_back(board[row][col]);
        }

        vector<int> newCol = vector<int>(n-temp.size(), 0);
        for (auto elem : temp) newCol.push_back(elem);

        for (int row = 0; row < n; row++) board[row][col] = newCol[row];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0; 
}