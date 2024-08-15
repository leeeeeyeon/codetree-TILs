#include <iostream>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int a, b;

    // +1: 시작점, -1: 끝점
    vector<tuple<int, int, int>> points; // {좌표, +1 -1, 선분 번호}
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        points.push_back(make_tuple(a, 1, i));
        points.push_back(make_tuple(b, -1, i));
    }

    sort(points.begin(), points.end());

    int point, status, idx;
    int cnt = 0;
    unordered_set<int> us;
    for (int i = 0; i < 2 * n; i++) {
        tie(point, status, idx) = points[i];

        // 시작점인 경우
            // 남아있는 선분이 없다면 cnt++
            // 선분을 set에 넣어줌
        if (status == 1) {
            if (us.size() == 0) cnt++;

            us.insert(idx);
        } else { // 끝점인 경우 선분을 set에서 제거
            us.erase(idx);
        }
    }

    cout << cnt;

    return 0;
}

// 피드백: set에 point를 넣어주면 겹칠 수 있음