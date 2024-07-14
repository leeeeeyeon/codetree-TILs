#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    unordered_set<int> us;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        us.insert(elem);
    }

    cout << us.size();
    
    return 0;
}