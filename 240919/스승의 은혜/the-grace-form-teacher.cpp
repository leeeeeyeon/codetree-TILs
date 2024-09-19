#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    int sumA = a.first + a.second;
    int sumB = b.first + b.second;
    if (sumA == sumB) {
        return a.first < b.first;
    }

    return sumA < sumB;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, b; // 학생 수, 예산
    cin >> n >> b;

    int p, s; // 선물의 가격, 배송비
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        cin >> p >> s;
        arr.push_back({p, s});
    }

    sort(arr.begin(), arr.end(), comp);

    int cnt = 0;
    for (auto elem : arr) {
        // 예산이 다 떨어진 경우
        if (b <= 0) break;

        int sum = elem.first + elem.second;
        // 현재 예산으로 학생의 선물을 사지 못할 경우
        if (b < sum) {
            // 쿠폰을 적용하면 살 수 있는 경우
            int couponPrice = elem.first / 2 + elem.second;
            if (couponPrice < b) {
                b -= couponPrice;
                cnt++;
            }
        } else { // 현재 예산으로 학생의 선물을 살 수 있는 경우
            b -= sum;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}