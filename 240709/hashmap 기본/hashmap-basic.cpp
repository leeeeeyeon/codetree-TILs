#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    unordered_map<int, int> mp;
    while(n--) {
        string cmd;
        int k, v;
        cin >> cmd;

        if (cmd == "add") {
            cin >> k >> v;
            mp[k] = v;
        } else if (cmd == "remove") {
            cin >> k;
            mp.erase(k);
        } else { // cmd == "find"
            cin >> k;
            if (mp.find(k) != mp.end()) cout << mp[k] << '\n';
            else cout << "None" << '\n';
        }
    }
    return 0;
}