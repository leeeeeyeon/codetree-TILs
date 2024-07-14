#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    unordered_set<int> usA;
    unordered_set<int> usB;

    int elem;
    for (int i = 0; i < a; i++) {
        cin >> elem;
        usA.insert(elem);
    }

    for (int i = 0; i < b; i++) {
        cin >> elem;
        usB.insert(elem);
    }

    unordered_set<int> result;

    // A - B
    for (auto it = usA.begin(); it != usA.end(); it++) {
        if (usB.find(*it) == usB.end()) result.insert(*it);
    }

    // B - A
        for (auto it = usB.begin(); it != usB.end(); it++) {
        if (usA.find(*it) == usA.end()) result.insert(*it);
    }

    cout << result.size();

    return 0;
}