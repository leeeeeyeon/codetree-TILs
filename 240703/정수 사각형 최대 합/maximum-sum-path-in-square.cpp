#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vvi board = vvi(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j] += max(board[i-1][j], board[i][j-1]);
        }
    }

    cout << board[n][n];
    
    return 0;
}