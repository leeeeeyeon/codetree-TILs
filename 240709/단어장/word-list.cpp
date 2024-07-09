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

    map<string, int> mp;
    while (n--) {
        string str;
        cin >> str;
        mp[str]++;
    }

    for (auto elem : mp) cout << elem.first << ' ' << elem.second << '\n';
    
    return 0;
}