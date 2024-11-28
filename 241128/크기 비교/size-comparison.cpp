#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

typedef vector<vector<int>> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vvi dist = vvi(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b; // a가 b보다 크다
        cin >> a >> b;
        dist[a][b] = 1;
    }

    vector<int> result = vector<int>(n+1, n-1);

    // 플로이드-와샬
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] >= INF || dist[k][j] >= INF) {
                    continue;
                }

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
 
            if (dist[i][j] >= INF && dist[j][i] >= INF) {
                cnt++;
            }
        }
        result[i] = cnt;
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}