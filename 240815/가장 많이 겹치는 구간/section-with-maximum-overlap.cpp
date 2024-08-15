#include <iostream>
#include <algorithm>

#define MAX_X 200'000

using namespace std;

int arr[MAX_X+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int x1, x2;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        arr[x1]++;
        arr[x2]--;

        mx = max({mx, x1, x2});
    }

    for (int i = 1; i <= mx; i++) {
        arr[i] += arr[i-1];
    }

    int result = 0;
    for (int i = 1; i <= mx; i++) {
        result = max(result, arr[i]);
    }

    cout << result;

    return 0;
}