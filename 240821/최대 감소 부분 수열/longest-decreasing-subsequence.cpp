#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr = vector<int>(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // dp[i]: i번째 원소를 마지막으로 하는 LDS의 길이
    // 0 ~ i-1번째 원소 중 arr[i]보다 큰 값을 가지는 원소 중 가장 큰 DP 값 + 1
    vector<int> dp = vector<int>(n+1, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) dp[i] = max(dp[j]+1, 1);
        }
    }

    int result = 0;
    for (auto elem : dp) result = max(result, elem);

    cout << result;

    return 0;
}