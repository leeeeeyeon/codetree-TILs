#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int s, e;
    vector<pair<int, int>> points; // {날짜, 시작점 끝점 여부}
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        points.push_back({s, 1});
        points.push_back({e, -1});
    }

    sort(points.begin(), points.end());

    int cnt = 0; // 방의 수
    int mx = 0; // 최대로 겹치는 구간의 수
    for (auto point : points) {
        if (point.second == 1) cnt++;
        else if (point.second == -1) cnt--;

        mx = max(mx, cnt);
    }

    cout << mx;

    return 0;
}