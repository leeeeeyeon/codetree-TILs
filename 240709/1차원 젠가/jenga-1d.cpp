#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 처음에 놓여있는 블럭의 수
    cin >> n;

    vector<int> zenga;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        zenga.push_back(elem);
    }

    int s1, e1, s2, e2;
    cin >> s1 >> e1;
    cin >> s2 >> e2;
    
    s1--;
    e1--;
    s2--;
    e2--;

    // 블록 빼기 작업 1
    vector<int> zenga2;
    for (int i = 0; i < zenga.size(); i++) {
        if (i >= s1 && i <= e1) continue;

        zenga2.push_back(zenga[i]);
    }

    // 블록 빼기 작업 2
    vector<int> zenga3;
    for (int i = 0; i < zenga2.size(); i++) {
        if (i >= s2 && i <= e2) continue;

        zenga3.push_back(zenga2[i]);
    }

    cout << zenga3.size() << '\n';
    for (auto elem : zenga3) cout << elem << '\n';
    
    return 0;
}