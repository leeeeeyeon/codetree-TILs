#include <iostream>
#include <unordered_map>

#define MAX_N 100'000

using namespace std;

typedef long long ll;

int arr[MAX_N];
unordered_map<ll, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        arr[i] = elem;
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        int diff = k - arr[i];
        ret += mp[diff];

        mp[arr[i]]++;
    }

    cout << ret;
    
    return 0;
}