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
    double total = 0;
    while(n--) {
        string str;
        cin >> str;

        mp[str]++;
        total++;
    }

    cout<<fixed;
    cout.precision(4); // 정수와 소수점 부분을 합친 자리수
    for (auto elem : mp) {
        double percent = (elem.second / total) * 100;
        cout << elem.first << ' ' << percent << '\n';
    }

    return 0;
}