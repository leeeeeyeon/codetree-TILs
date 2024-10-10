#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        pq.push(num);
    }

    int answer = 0;
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        answer += (first + second);
        pq.push(first + second);
    }

    cout << answer;

    return 0;
}