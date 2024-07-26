#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a;
string str;

int countLength(string str) {
    string result = "";
    for (int i = 0; i < str.size(); i++) {
        char target = str[i];
        int cnt = 1;
        
        for (int j = i+1; j < str.size(); j++) {
            if (target == str[j]) cnt++;
            else break;
        }
        
        result += target;
        result += to_string(cnt);

        i += cnt-1;
    }

    return result.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a;

    // Shift 연산 대신 문자열 2번 반복
    str = a + a;

    int minSize = 100;
    for (int i = 0; i < a.size(); i++) {
        string shiftedString = str.substr(i, a.size());

        minSize = min(minSize, countLength(shiftedString));
    }

    cout << minSize;
    return 0;
}