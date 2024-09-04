#include <iostream>

#define MAX_N 100'000
#define MAX_K 100'000

using namespace std;

int parent[MAX_N+1];
int route[MAX_K];

int findParent(int x) {
    if (x == parent[x]) return x;

    return parent[x] = findParent(parent[x]);
}

void merge(int x, int y) {
    int X = findParent(x);
    int Y = findParent(y);

    if (X == Y) return;

    if (X < Y) parent[Y] = parent[X];
    else parent[X] = parent[Y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    // parent 배열 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        merge(x, y);
    }

    for (int i = 0; i < k; i++) {
        cin >> route[i];
    }

    for (int i = 0; i < k-1; i++) {
        if (findParent(route[i]) != findParent(route[i+1])) {
            cout << 0;

            return 0;
        }
    }

    cout << 1;

    return 0;
}