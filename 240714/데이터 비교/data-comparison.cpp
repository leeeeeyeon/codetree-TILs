#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    
    cin >> n;
    unordered_set<int> arr1;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        arr1.insert(elem);
    }

    cin >> m;
    vector<int> arr2 = vector<int>(m, 0);
    for (int i = 0; i < m; i++) cin >> arr2[i];

    for (auto elem : arr2) {
        if (arr1.find(elem) != arr1.end()) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
    
    return 0;
}