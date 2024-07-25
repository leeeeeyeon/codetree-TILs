#include <iostream>

#define MAX_N 1'000
#define MOD 10'007

using namespace std;

int dp[MAX_N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] * 2) % MOD;
    }

    cout << dp[n];

    return 0;
}