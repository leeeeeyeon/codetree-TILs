#include <iostream>

#define MAX_N 100'000

using namespace std;

int parent[MAX_N+1];

int findParent(int x) {
    if (x == parent[x]) return x;

    return parent[x] = findParent(parent[x]);
}

void merge(int a, int b) {
    int A = findParent(a);
    int B = findParent(b);

    if (A == B) return;

    if (A < B) parent[B] = parent[A];
    else parent[B] = parent[A];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // parent 배열 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
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

            int cnt = 0; // 정점 a와 연결된 정점의 개수
            for (int i = 1; i <= n; i++) {
                if (parent[i] == parent[a]) cnt++;
            }

            cout << cnt << '\n';
        }

        for (int i = 1; i <= n; i++) {
            parent[i] = findParent(parent[i]);
        }
    }

    return 0;
}