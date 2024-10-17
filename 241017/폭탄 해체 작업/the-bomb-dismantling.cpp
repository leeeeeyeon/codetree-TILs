#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define SCORE first
#define TIME second

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.SCORE > b.SCORE;

    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 폭탄의 수
    cin >> n;
    
    vector<pair<int, int>> arr;
    int score, time;
    for (int i = 0; i < n; i++) {
        cin >> score >> time;
        arr.push_back({score, time});
    }

    sort(arr.begin(), arr.end(), comp);

    int result = 0;
    int maxT = arr[n-1].TIME;
    int idx = n-1;

    priority_queue<int> pq;
    for (int t = maxT; t > 0; t--) {
        while (idx >= 0 && arr[idx].TIME >= t) {
            pq.push(arr[idx].SCORE);
            idx--;
        }

        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result;

    return 0;
}