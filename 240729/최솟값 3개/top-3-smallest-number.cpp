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

            cout << a * b * c << '\n';

            pq.push(-a);
            pq.push(-b);
            pq.push(-c);
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}