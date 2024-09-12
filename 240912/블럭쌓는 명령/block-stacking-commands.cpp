#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; // 칸의 수, 명령의 수
    cin >> n >> k;

    vector<int> arr = vector<int>(n+2, 0);
    // -1 +1 technique
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        arr[a]++;
        arr[b+1]--;
    }

    // 각 칸에 쌓인 블럭 계산
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i-1];
    }

    sort(arr.begin(), arr.end());

    cout << arr[n/2+2];
    
    return 0;
}