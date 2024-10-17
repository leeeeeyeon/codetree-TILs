#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int answer = 100000;
    for (int i = n/5; i >= 0; i--) {
        // 5원 동전을 i개 씀 > (n-5*i)원 남음
        // 만약 (n-5*i)가 짝수면 answer를 min 비교해서 갱신
        if ((n-5*i) % 2 == 0) answer = min(answer, i+(n-5*i)/2);
    }

    if (answer == 100000) cout << -1;
    else cout << answer;

    return 0;
}