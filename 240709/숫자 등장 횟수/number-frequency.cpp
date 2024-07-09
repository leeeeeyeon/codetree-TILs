#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // 원소의 수, 질의의 수
    cin >> n >> m;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        mp[elem]++;
    }

    for (int i = 0; i < m; i++) {
        int elem;
        cin >> elem;
        cout << mp[elem] << ' ';
    }
    
    return 0;
}