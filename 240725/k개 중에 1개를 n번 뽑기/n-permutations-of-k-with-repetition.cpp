#include <iostream>
#include <vector>

using namespace std;

int k, n;
vector<int> arr;

void combi(int k, int n) {
    // 재귀 탈출 조건: arr의 크기 == n
    if (arr.size() == n) {
        for (auto elem : arr) cout << elem << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= k; i++) {
        arr.push_back(i);
        combi(k, n);
        arr.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n;

    combi(k, n);
    return 0;
}