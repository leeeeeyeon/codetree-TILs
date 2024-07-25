#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> arr;

    cin >> n;
    while(n--) {
        int elem;
        cin >> elem;
        arr.push_back(elem);
    }

    sort(arr.begin(), arr.end());
    for (int i = arr.size()-1; i >= 0; i--) {
        cout << arr[i] << ' ';
    }
    
    return 0;
}