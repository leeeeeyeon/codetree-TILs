#include <iostream>
#include <vector>

using namespace std;

int parent[MAX_N+1];

int findParent(int x) {
    if (x == parent[x]) return x;

    return parent[x] = findParent(parent[x]);
}

void merge(int a, int b) {
    int A = findParent(a);
    int B = findParent(b);

    if (A < B) parent[B] = parent[A];
    else if (A > B) parent[A] = parent[B];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // 정수의 개수, 연산의 횟수
    cin >> n >> m;

    // parent 배열 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;

        if (cmd == 0) {
            // a가 포함된 집합과 b가 포함된 집합을 합침
            // 이미 같은 집합에 속한다면 아무 것도 하지 X
            merge(a, b);
        }
        else if (cmd == 1) {
            // a와 b가 같은 집합 > 1 출력
            // 그렇지 X > 0 출력
            if (findParent(a) == findParent(b)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

    return 0;
}