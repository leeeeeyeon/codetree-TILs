#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<ll> arr = vector<ll>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll mn = arr[0];
    ll diffMax = 0;
    for (int i = 0; i < n; i++) {
        mn = min(mn, arr[i]);
        ll diff = arr[i] - mn;
        diffMax = max(diffMax, diff);
    }

    cout << diffMax;

    return 0;
}