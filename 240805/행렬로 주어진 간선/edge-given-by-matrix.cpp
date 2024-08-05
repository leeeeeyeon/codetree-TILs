#include <iostream>
#include <algorithm>

#define MAX_N 100
#define INF 987654321

using namespace std;

int board[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) board[i][j] = INF;
        }
    }

    // 플로이드 와샬
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) board[i][j] = 1;
                else board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }

    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] >= INF) cout << 0 << ' ';
            else cout << 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}