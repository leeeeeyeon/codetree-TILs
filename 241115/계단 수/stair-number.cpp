#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<vector<int>> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // dp[i][j] = 길이가 n이고 j로 끝나는 계단 수의 개수
    vvi dp = vvi(n+1, vector<int>(10, 0));

    // n=1일 때 초기화
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    int mod = pow(10, 9) + 7;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) dp[i][0] = dp[i-1][1] % mod;
            else if (j == 9) dp[i][9] = dp[i-1][8] % mod;
            else dp[i][j] = dp[i-1][j-1] % mod + dp[i-1][j+1] % mod;
        }
    }
    
    long long sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum += dp[n][i];
    }

    cout << sum % mod;

    return 0;
}