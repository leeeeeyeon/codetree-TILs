#include <iostream>
#include <vector>
using namespace std;

void makeArr(int n, vector<int> &arr, vector<bool> &visited) {
    if (arr.size() == n) {
        for (int elem : arr) cout << elem << ' ';
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            arr.push_back(i);
            visited[i] = true;

            makeArr(n, arr, visited);

            arr.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr;
    vector<bool> visited = vector<bool>(n+1, false);

    makeArr(n, arr, visited);

    return 0;
}