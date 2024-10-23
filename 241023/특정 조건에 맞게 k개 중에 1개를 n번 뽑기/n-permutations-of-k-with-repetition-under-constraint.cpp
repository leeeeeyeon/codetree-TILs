#include <iostream>
#include <vector>

using namespace std;

void printNumbers(int k, int n, vector<int> &arr) {
    if (arr.size() == n) {
        int cnt = 0;
        int target = arr[0];
        for (int elem : arr) {
            if (elem == target) cnt++;
            else {
                target = elem;
                cnt = 1;
            }
        }

        if (cnt < 3) {
            for (int elem : arr) cout << elem << ' ';
            cout << '\n';
        }

        return;
    }

    for (int i = 1; i <= k; i++) {
        arr.push_back(i);
        printNumbers(k, n, arr);
        arr.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<int> arr;
    printNumbers(k, n, arr);

    return 0;
}