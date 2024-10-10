#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int num;
    for (int i = 0; i < m; i++) {
        cin >> num;

        int left = 0;
        int right = arr.size()-1;

        int answer = -1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] == num) {
                answer = mid+1;
                break;
            } else if (arr[mid] > num) { // 왼쪽 구간 탐색
                right = mid-1;
            } else { // arr[mid] < num, 오른쪽 구간 탐색
                left = mid + 1;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}