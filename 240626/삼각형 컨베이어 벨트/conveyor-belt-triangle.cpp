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

    // 회전 횟수를 줄이기 위해 t를 나눈다
    t %= (n * 9);

    // 3*n짜리 벡터를 만든다
    vector<int> belt = {};

    int k = 3;
    while(k--) {
        vector<int> line = vector<int>(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> line[i];
        }

        for (auto elem : line) belt.push_back(elem);
    }

    // 오른쪽으로 t번 회전
    rotate(belt.begin(), belt.end()-t, belt.end());

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << belt[i*n+j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}