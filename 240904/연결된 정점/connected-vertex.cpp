#include <iostream>

#define MAX_N 100'000

using namespace std;

int parent[MAX_N+1];
int sz[MAX_N+1]; // 연결된 정점의 개수를 배열로 따로 관리

int findParent(int x) {
    if (x == parent[x]) return x;

    return parent[x] = findParent(parent[x]);
}

void merge(int a, int b) {
    int A = findParent(a);
    int B = findParent(b);

    if (A == B) return;

    if (A < B) {
        parent[B] = parent[A];
        sz[A] += sz[B];
    }

    else {
        parent[B] = parent[A];
        sz[B] += sz[A];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // parent, sz 배열 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        char cmd;
        cin >> cmd;

        if (cmd == 'x') {
            int a, b;
            cin >> a >> b;

            merge(a, b);
        }
        else if (cmd == 'y') {
            int a;
            cin >> a;

            cout << sz[a] << '\n';
        }
    }

    return 0;
}