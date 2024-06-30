#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp = {0, 1, 2};

    for (int i=3; i <= n; i++) {
        dp.push_back((dp[i-2]+dp[i-1]) % 10'007);
    }

    cout << dp[n];
    
    return 0;
}