#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tiii;

// 우선순위 큐에서는 back이 top
struct cmp {
    bool operator()(tiii a, tiii b) {
        if (get<0>(a) == get<0>(b)) {
            if (get<1>(a) == get<1>(b)) {
                return get<2>(a) > get<2>(b);
            }
            return get<1>(a) > get<2>(b);
        }
        return get<0>(a) > get<0>(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // 점의 갯수, 반복 횟수
    cin >> n >> m;

    priority_queue<tiii, vector<tiii>, cmp> pq;
    while (n--) {
        int x, y, dist;
        cin >> x >> y;
        dist = abs(x) + abs(y);

        pq.push(make_tuple(dist, x, y));
    }

    // 원점에서 가장 가까운 점의 x, y값에 2를 더한다
    while (m--) {
        // 원점에서 가장 가까운 점
        tiii point = pq.top();
        pq.pop();

        // x, y에 2를 더한다
        int x = get<1>(point) + 2;
        int y = get<2>(point) + 2;
        int dist = abs(x) + abs(y);

        // 다시 pq에 넣는다
        pq.push(make_tuple(dist, x, y));
    }

    tiii top = pq.top();
    cout << get<1>(top) << ' ' << get<2>(top);

    return 0;
}