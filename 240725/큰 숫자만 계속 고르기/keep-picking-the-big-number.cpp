#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        pq.push(elem);
    }

    while(m--) {
        int mx = pq.top();
        pq.pop();
        pq.push(mx-1);
    }

    cout << pq.top();

    return 0;
}