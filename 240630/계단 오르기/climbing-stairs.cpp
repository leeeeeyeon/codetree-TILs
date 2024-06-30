#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp = {0, 0, 1, 1};

    for (int i = 4; i <= n; i++) {
        dp.push_back((dp[i-2] + dp[i-3]) % 10'007);
    }

    cout << dp[n];
    
    return 0;
}