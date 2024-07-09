#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    unordered_map<string, int> mp;
    while(n--) {
        string str;
        cin >> str;

        mp[str]++;
    }

    int ret = 0;
    for (auto elem : mp) {
        if (elem.second > ret) ret = elem.second;
    }

    cout << ret;
    
    return 0;
}