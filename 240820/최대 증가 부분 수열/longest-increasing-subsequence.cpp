#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr = vector<int>(n, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> dp;
    dp.push_back(0);
    for (int i = 1; i <= n; i++) {
        // dp 배열이 비어있거나 현재 원소가 마지막 원소보다 클 때
        if (dp.empty() || arr[i] > dp[dp.size()-1]) dp.push_back(arr[i]);
        else {
            int lb = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[lb] = arr[i];
        }
    }

    cout << dp.size() - 1;

    return 0;
}