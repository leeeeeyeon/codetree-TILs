#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;

    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> arr;
    int s, e; // 시작 시각, 끝나는 시각
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        arr.push_back({s, e});
    }

    sort(arr.begin(), arr.end(), comp);

    // 직전 회의의 끝나는 시각과 현재 회의의 시작 시각 비교
    // 두 값이 같아도 됨
    int cnt = 0;
    int prevEnd = -1;
    for (auto elem : arr) {
        int curStart = elem.first;
        int curEnd = elem.second;

        // 회의 가능 = 이전 회의 끝나는 시각 이후에 현재 회의 시작
        if (prevEnd <= curStart) {
            cnt++;
            prevEnd = curEnd;
        }
    }

    cout << cnt;

    return 0;
}