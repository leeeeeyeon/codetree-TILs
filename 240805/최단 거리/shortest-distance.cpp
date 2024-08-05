#include <iostream>
#include <algorithm>

#define MAX_N 100
#define INF 987654321

using namespace std;

int dist[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // 장소의 개수, 이동 시간을 구해볼 횟수
    cin >> n >> m;

    // 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // 플로이드 와샬
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    // 출력
    int a, b;
    while(m--) {
        cin >> a >> b;
        cout << dist[a-1][b-1] << '\n';
    }

    return 0;
}