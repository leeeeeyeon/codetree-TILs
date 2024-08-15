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

    vector<pair<int, int>> points; // {좌표, 시작점 끝점 여부}
    int x1, x2; // 주어지는 x값들은 모두 다름
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        points.push_back({x1, 1});
        points.push_back({x2, -1});
    }

    sort(points.begin(), points.end());

    int mx = 0;
    int cnt = 0; // 겹치는 구간의 횟수
    for (auto point : points) {
        if (point.second == 1) {
            cnt++;
            mx = max(mx, cnt);
        } 
        else if (point.second == -1) {
            cnt--;
        }
    }

    cout << mx;

    return 0;
}