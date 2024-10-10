#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string name;
    unordered_map<string, int> um;
    for (int i = 0; i < n; i++) {
        vector<string> temp;
        for (int j = 0; j < 3; j++) {
            cin >> name;
            temp.push_back(name);
        }

        sort(temp.begin(), temp.end());

        string result = "";
        for (string elem : temp) result += elem;

        um[result]++;
    }

    int answer = 0;
    for (auto elem : um) {
        answer = max(answer, elem.second);
    }

    cout << answer;

    return 0;
}