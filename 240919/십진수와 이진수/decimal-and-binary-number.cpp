#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    // 10진수 계산
    int decimalNum = 0;
    for (int i = 0; i < s.size(); i++) {
        int tempNum = s[s.size()-i-1] - '0';
        decimalNum += pow(2, i) * tempNum;
    }

    // 십진수에 17배
    decimalNum *= 17;

    // 다시 이진수로 표현
    string tempStr = "";

    // 순서가 반대로 저장됨
    while (decimalNum != 0) {
        tempStr += to_string(decimalNum % 2);
        decimalNum /= 2;
    }

    string result = "";
    for (int i = tempStr.size()-1; i >= 0; i--) {
        result += tempStr[i];
    }

    cout << result;
    
    return 0;
}