#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    map<int, int> mp;
    while (n--) {
        string cmd;
        int key, value;

        cin >> cmd;
        if (cmd == "add") {
            cin >> key >> value;
            mp[key] = value;
        } else if (cmd == "remove") {
            cin >> key;
            mp.erase(key);
        } else if (cmd == "find") {
            cin >> key;
            if (mp.find(key) != mp.end()) cout << mp[key] << '\n';
            else cout << "None" << '\n';
        } else { // cmd == "print_list"
            if (mp.empty()) cout << "None" << '\n';
            else {
                for (auto elem : mp) cout << elem.second << ' ';
                cout << '\n';
            }
        }
    }

    return 0;
}