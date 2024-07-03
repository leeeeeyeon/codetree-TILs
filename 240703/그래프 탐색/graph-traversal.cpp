#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

void dfs(int n, vvi &graph, vector<int> &visited) {
    // 재귀
    for (auto elem : graph[n]) {
        if (visited[elem]) continue;
        visited[elem] = true;
        dfs(elem, graph, visited);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // 정점, 간선
    cin >> n >> m;

    vvi graph = vvi(n+1);
    vector<int> visited = vector<int>(n+1, false);

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visited[1] = true;
    dfs(1, graph, visited);

    int cnt = 0;
    for (auto elem : visited) {
        if (elem) cnt++;
    }

    cout << cnt - 1;
    return 0;
}