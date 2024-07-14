#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    unordered_set<int> us;

    while (n--) {
        string cmd;
        int x;
        cin >> cmd >> x;

        if (cmd == "add") {
            us.insert(x);
        } else if (cmd == "remove") {
            us.erase(x);
        } else { // cmd == "find"
            if (us.find(x) != us.end()) cout << "true" << '\n';
            else cout << "false" << '\n';
        }
    }
    return 0;
}