#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> pq;
    while (n--) {
        int elem;
        cin >> elem;
        pq.push(-elem);

        if (pq.size() >= 3) {            
            int a = -pq.top();
            pq.pop();

            int b = -pq.top();
            pq.pop();

            int c = -pq.top();
            pq.pop();

            // 형 변환을 붙이지 않으면 결과가 int 타입으로 계산되어 오버플로우 발생
            long long result = (long long) a * b * c;
            cout << result << '\n';

            pq.push(-a);
            pq.push(-b);
            pq.push(-c);
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}