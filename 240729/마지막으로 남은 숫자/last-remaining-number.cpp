#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> pq;
    while(n--) {
        int elem;
        cin >> elem;
        pq.push(elem);
    }

    while(pq.size() >= 2) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        if (a == b) continue;
        pq.push(abs(a-b));
    }

    if (pq.empty()) cout << -1;
    else cout << pq.top();

    return 0;
}