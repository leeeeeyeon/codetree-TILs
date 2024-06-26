#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    cin >> n >> t;
    
    vector<int> belt = {};
    // 실제로는 2*n짜리 배열
    for (int k = 0; k < 2; k++) {
        vector<int> line = vector<int>(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> line[i];
        }
        for (auto elem : line) belt.push_back(elem);
    }

    rotate(belt.begin(), belt.end()-t, belt.end());

    for (int i = 0; i < n; i++) {
        cout << belt[i] << ' ';
    }
    cout << '\n';
    for (int i = n; i < 2*n; i++) {
        cout << belt[i] << ' ';
    }

    return 0;
}