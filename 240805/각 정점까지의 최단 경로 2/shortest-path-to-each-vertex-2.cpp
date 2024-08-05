#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100

using namespace std;

typedef long long ll;

ll dist[MAX_N+1][MAX_N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // 정점, 간선
    cin >> n >> m;

    // dist 배열 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX;
        }
    }

    int a, b;
    ll c;
    while (m--) {
        cin >> a >> b >> c;
        // 두 정점을 연결하는 간선이 여러 개 주어질 수도 있는 점 주의!
        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] >= INT_MAX) cout << -1 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}