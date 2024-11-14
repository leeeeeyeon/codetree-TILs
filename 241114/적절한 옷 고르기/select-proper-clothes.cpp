#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // 옷의 수, 날짜
    cin >> n >> m;

    vvi arr = vvi(m+1); // i번째 날에 입을 수 있는 옷
    unordered_map<int, int> um; // i번째 옷의 화려함

    int s, e, v;
    for (int i = 0; i < n; i++) {
        cin >> s >> e >> v;

        um[i] = v;
        for (int j = s; j <= e; j++) {
            arr[j].push_back(i);
        }
    }

    vvi dp = vvi(m+1, vector<int>(n, 0));
    for (int i = 2; i <= m; i++) {
        for (int cur : arr[i]) {
            // 오늘은 cur번째 옷을 입음
            for (int prev : arr[i-1]) {
                // 어제는 prev번째 옷을 입음
                int diff = abs(um[cur] - um[prev]);
                dp[i][cur] = max(dp[i][cur], dp[i-1][prev] + diff);
            }
        }
    }

    cout << *max_element(dp[m].begin(),dp[m].end());

    return 0;
}