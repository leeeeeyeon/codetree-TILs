#include <iostream>
#include <vector>

using namespace std;

int mod = 1'000'00'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp = {1, 2, 7, 22};

    for(int i=3; i<= n; i++) {
        dp.push_back((dp[i-1]*2 + dp[i-2]*3 + dp[i-3]*2 + dp[i-4]*2) % mod);
    }

    cout << dp[n];

    return 0;
}