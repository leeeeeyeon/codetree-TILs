#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; // 동전의 종류 개수, 금액
    cin >> n >> k;

    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    sort(coins.begin(), coins.end(), comp);

    int ret = 0;
    for (auto coin : coins) {
        if (k == 0) break;
        ret += (k / coin);
        k %= coin;
    }

    cout << ret;

    return 0;
}