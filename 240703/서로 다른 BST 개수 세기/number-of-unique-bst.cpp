#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp = vector<int>(n+1, 0);
    
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        int k = 0;
        for(int j = 0; j < i; j++) k += dp[j] * dp[n-j-1];

        dp[i] = k;
    }

    cout << dp[n];

    return 0;
}