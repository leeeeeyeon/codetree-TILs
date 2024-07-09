#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        // 맵에 이미 존재한다면 pass
        if (mp.find(elem) != mp.end()) continue;
        // 그렇지 않다면 현재 인덱스 위치를 저장
        else mp[elem] = i+1;
    }

    for (auto elem : mp) cout << elem.first << ' ' << elem.second << '\n';
    
    return 0;
}