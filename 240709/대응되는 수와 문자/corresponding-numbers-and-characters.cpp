#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // 숫자의 개수, 조사할 값의 개수
    cin >> n >> m;

    unordered_map<int, string> mp1; // 숫자로 문자열 검색
    unordered_map<string, int> mp2; // 문자열로 숫자 검색
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        mp1[i] = s;
        mp2[s] = i;
    }

    // 조사할 값을 우선 string으로 받고 숫자인지 검사
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        // 알파벳의 아스키 코드값은 65부터 시작
        // 아스키 코드값이 65 미만이면 수라고 판단
        if (s[0] < 65) { // 숫자가 들어온 경우
            // 문자열 반환
            int num = stoi(s);
            cout << mp1[num] << '\n';
        } else { // 문자열이 들어온 경우
            // 숫자 반환
            cout << mp2[s] << '\n';
        }
    }

    return 0;
}