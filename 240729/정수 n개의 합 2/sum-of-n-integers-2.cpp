#include <iostream>

#define MAX_N 100'000

using namespace std;

int arr[MAX_N];
int sum[MAX_N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum[i+1] = sum[i] + arr[i];
    }

    int mx = 0;
    for (int i = 1; i <= n-k; i++) {
        int rangeSum = sum[i+2] - sum[i];
        if (rangeSum > mx) mx = rangeSum;
    }

    cout << mx;

    return 0;
}