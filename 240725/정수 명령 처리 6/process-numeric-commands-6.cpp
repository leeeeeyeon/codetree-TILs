#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> pq;
    while(n--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int a;
            cin >> a;
            pq.push(a);
        } else if (cmd == "pop") {
            cout << pq.top() << '\n';
            pq.pop();
        } else if (cmd == "size") {
            cout << pq.size() << '\n';
        } else if (cmd == "empty") {
            cout << pq.empty() << '\n';
        } else if (cmd == "top") {
            cout << pq.top() << '\n';
        }
    }

    return 0;
}