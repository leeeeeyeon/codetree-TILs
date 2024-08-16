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

    if (n == 1) {
        cout << 1;

        return 0;
    }

    sort(points.begin(), points.end());

    int cnt = 0; // 방의 수
    int mx = 0; // 최대로 겹치는 구간의 수
    int prevEnd = 0;
    for (auto point : points) {
        if (point.second == 1) {
            cnt++;
            if (prevEnd == point.first) cnt++;
        }
        else if (point.second == -1) {
            cnt--;
            prevEnd = point.first;
        }

        mx = max(mx, cnt);

        if (point.second == 1 && prevEnd == point.first) cnt--;
    }

    cout << mx;

    return 0;
}