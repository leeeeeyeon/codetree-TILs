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

    int n, m; // 정점의 수, 간선의 수
    cin >> n >> m;

    vvi distance = vvi(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; i++) {
        distance[i][i] = 0;
    }

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        distance[a][b] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    int mn = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            mn = min(mn, distance[i][j] + distance[j][i]);
        }
    }

    cout << mn;

    return 0;
}