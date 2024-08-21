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

    if (n == 1) {
        cout << 1;
        return 0;
    }

    vector<int> dp;
    dp.push_back(0);
    dp.push_back(arr[1]);

    for (int i = 2; i <= n; i++) {
        // 순차 탐색으로 1~i번째 원소 중 가장 작은 원소를 찾아
        int mn = INT_MAX;
        for (int j = 1; j <= i; j++) {
            mn = min(mn, arr[j]);
        }

        // dp의 마지막 원소랑 비교
        // mn이 더 크면 갱신
        // mn이 더 작으면 뒤에 원소 추가
        if (dp[dp.size()-1] < mn) {
            dp[dp.size()-1] = mn;
        } else if (dp[dp.size()-1] > mn) {
            dp.push_back(mn);
        }
    }

    cout << dp.size() - 1;

    return 0;
}