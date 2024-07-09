#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

// n개 중 2개를 고르는 조합
vector<vector<int>> combi(vector<int> arr) {
    vector<vector<int>> results;

    if (arr.size() < 2) return results;

    vector<int> temp(arr.size(), 0);
    temp[0] = temp[1] = 1;

    do {
        vector<int> ret;
        for (int i = 0; i < arr.size(); i++) {
            if (temp[i] == 1) ret.push_back(arr[i]);
        }
        results.push_back(ret);
    } while (prev_permutation(temp.begin(), temp.end()));

    return results;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll k;
    cin >> n >> k;

    set<ll> s;
    for (int i = 0; i < n; i++) {
        ll elem;
        cin >> elem;
        s.insert(elem);
    }

    vector<int> arr = vector<int>(s.begin(), s.end());

    vector<vector<int>> results = combi(arr);
    int cnt = 0;
    for (auto ret : results) {
        ll sum = ret[0] + ret[1];
        if (sum == k) cnt++;
    }

    cout << cnt;

    return 0;
}