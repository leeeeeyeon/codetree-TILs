#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

#define SCORE first
#define TIME second

// 시간 제한이 작은 것 먼저
// 같다면 점수가 큰 것 먼저
bool comp(pii a, pii b) {
    if (a.TIME == b.TIME) return a.SCORE > b.SCORE;

    return a.TIME < b.TIME;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pii> bombs; // {점수, 시간 제한}
    int score, time;
    for (int i = 0; i < n; i++) {
        cin >> score >> time;
        bombs.push_back({score, time});
    }

    sort(bombs.begin(), bombs.end(), comp);

    int t = 1; // 시간 흐름
    int idx = 0;
    int result = 0; // 얻을 수 있는 점수의 최댓값
    while(t <= bombs[bombs.size()-1].TIME) {
        // 시간 제한 내에 idx번째 폭탄 해체
        if (bombs[idx].TIME >= t) {
            result += bombs[idx].SCORE;
            idx++;
        } else { // bombs[idx].TIME < t
            // 시간 제한이 끝나서 폭탄이 터짐
            idx++;
        }

        t++;
    }

    cout << result;

    return 0;
}