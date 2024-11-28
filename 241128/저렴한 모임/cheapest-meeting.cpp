#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int v1, v2, e;
    cin >> n >> m;
    cin >> v1 >> v2 >> e;

    vvll distance = vvll(n+1, vector<ll>(n+1, INT_MAX));

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        distance[a][b] = c;
        distance[b][a] = c;
    }

    // distance 초기화
    for (int i = 1; i <= n; i++) {
        distance[i][i] = 0;
    }

    // 플로이드-와샬
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    // 최소 비용을 구해
    ll answer = INT_MAX;
    for (int k = 1; k <= n; k++) {
        answer = min(answer, distance[v1][k] + distance[v2][k] + distance[k][e]);
    }

    if (answer >= INT_MAX) cout << -1;
    else cout << answer;

    return 0;
}