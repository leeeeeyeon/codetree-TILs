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

        // arr에서 num이 몇 번째로 나왔는지 구해야 함 (인덱스 1부터 시작)
        
        // num이 범위 밖인 경우 -1 출력
        if (num < arr[0] || num >> arr[arr.size()-1]) {
            cout << -1 << '\n';
            continue;
        }

        // 이분 탐색
        int left = 0;
        int right = arr.size()-1;

        bool find = false;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] == num) {
                cout << mid+1 << '\n';
                find = true;
                break;
            } else if (arr[mid] > num) { // 왼쪽 구간 탐색
                right = mid-1;
            } else { // arr[mid] < num, 오른쪽 구간 탐색
                left = mid + 1;
            }
        }

        if (!find) cout << -1 << '\n';
    }

    return 0;
}