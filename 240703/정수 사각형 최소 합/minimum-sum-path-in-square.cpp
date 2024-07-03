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

    vvi dp = vvi(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dp[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            if (i == 1 && j == n) continue;
            if (i == 0 || j == 0) continue;

            if (i == 1) dp[i][j] += dp[i][j+1];
            else if (j == n) dp[i][j] += dp[i-1][j];
            else dp[i][j] += min(dp[i-1][j], dp[i][j+1]);
        }
    }

    cout << dp[n][1];

    return 0;
}