#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    return a + b > b + a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> nums;
    string num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end(), comp);

    string result = "";
    for (string elem : nums) {
        result += elem;
    }

    cout << result;

    return 0;
}