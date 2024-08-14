#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; // 칸 수, 명령의 수
    cin >> n >> k;

    // 쌓인 블럭의 개수
    vector<int> blocks = vector<int>(n+2, 0);
    int a, b;

    // 누적합으로 쌓인 블럭 계산
    for (int i = 0; i < k; i++) {
        cin >> a >> b;

        blocks[a]++;
        blocks[b+1]--;
    }

    for (int i = 1; i <= n; i++) {
        blocks[i] += blocks[i-1];
    }

    // blocks 정렬
    sort(blocks.begin(), blocks.end());

    // 가운데 값 출력
    cout << blocks[n/2+1];

    return 0;
}