#include <iostream>
#include <vector>

#define MAX_N 100

using namespace std;

int board[MAX_N+1][MAX_N+1];
int dp[MAX_N+1][MAX_N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1) {
                if (j == 1) continue;
                dp[i][j] = min(board[i][j], board[i][j-1]);
            }
            else if (j == 1) {
                dp[i][j] = min(board[i][j], board[i-1][j]);
            }
            else {
                dp[i][j] = min(board[i][j], max(dp[i-1][j], dp[i][j-1]));
            }
        }
    }

    cout << dp[n][n];

    return 0;
}