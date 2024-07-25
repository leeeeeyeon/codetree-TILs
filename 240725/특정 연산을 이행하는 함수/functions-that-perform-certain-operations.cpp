#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 3; i++) {
        int elem;
        cin >> elem;

        if (elem % 2 == 0) cout << elem / 2 << ' ';
        else cout << elem * 3 - 20 << ' ';
    }

    return 0;
}