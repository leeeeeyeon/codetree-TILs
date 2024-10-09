#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr = vector<int>(n, 0);
    bool allZero = true;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] >= 0) allZero = false;
    }

    ll answer = LLONG_MIN;

    // 모든 원소가 음수라면 제일 큰 원소 1개 선택
    if (allZero) {
        cout << *max_element(arr.begin(), arr.end());
    } else {
        for (int i = 0; i < n-1; i++) {
            ll sum = arr[i];
            // 연속 부분 수열의 원소들의 합이 음수가 아닐 동안
            while (i < n-1 && sum + arr[i+1] >= 0) {
                sum += arr[i+1];
                answer = max(answer, sum);
                i++;
            }
        }
        cout << answer;
    }

    return 0;
}