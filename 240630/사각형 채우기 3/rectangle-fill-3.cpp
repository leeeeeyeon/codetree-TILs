#include <iostream>
#include <vector>

#define MAX_N 1'000
#define MOD 1'000'000'007

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> dp = vector<long long>(MAX_N+1, 0);

    dp[0] = 1;
    dp[1] = 2;

    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1]*2 + dp[i-2]*3) % MOD;
        for (int j = i-3; j >= 0; j--) {
            dp[i] = (dp[i] + dp[j]*2) % MOD;
        }
    }

    cout << dp[n];

    return 0;
}