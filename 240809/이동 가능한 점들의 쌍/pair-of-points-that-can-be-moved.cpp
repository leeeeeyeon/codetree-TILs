#include <iostream>
#include <algorithm>

#define MAX_N 200
#define INF 987654321

using namespace std;

typedef long long ll;

ll dist[MAX_N+1][MAX_N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, p, q;
    cin >> n >> m >> p >> q;

    // dist 배열 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    int a, b, c; // a에서 b까지 가는 비용 c
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    // 1. 플로이드 와샬로 모든 정점에 대한 최단거리 계산
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // 2. 1부터 P까지 반복문 돌면서 start > k > end의 최단거리를 구해
    int start, end; // 출발점, 도착점
    int cnt = 0; // 이동 가능한 출발점과 도착점 쌍의 개수
    ll total = 0; // 이동 가능한 루트를 모두 이동했을 경우 드는 총 최소 비용의 합
    for (int i = 0; i < q; i++) {
        cin >> start >> end;

        ll mn = INF;
        for (int k = 1; k <= p; k++) {
            mn = min(mn, dist[start][k] + dist[k][end]);
        }

        if (mn < INF) {
            cnt++;
            total += mn;
        }
    }

    cout << cnt << '\n';
    cout << total << '\n';
    
    return 0;
}