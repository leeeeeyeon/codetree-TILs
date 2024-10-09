#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    double valuePerWeightA = (double) a.second / a.first;
    double valuePerWeightB = (double) b.second / b.first;

    return valuePerWeightA > valuePerWeightB;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // 보석의 개수, 가방의 크기
    cin >> n >> m;
    
    int w, v; // 보석의 무게, 가치
    vector<pair<int,int>> arr;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        arr.push_back({w, v});
    }

    // 무게 당 가치를 기준으로 arr 정렬
    sort(arr.begin(), arr.end(), comp);

    // 만약 남은 공간이 arr[i]보다 크면 arr[i]를 담는다
    // 그렇지 않다면 일부분만 담는다
    double answer = 0;
    for (auto elem : arr) {
        int weight = elem.first;
        int value = elem.second;
        double valuerPerWeight = (double) value / weight;

        if (m >= weight) {
            answer += value;
            m -= weight;
        }
        else { // m < weight
            answer += valuerPerWeight * m;
            break;
        }
    }

    // 소숫점 셋째자리까지 반올림하여 출력
    cout << fixed;
    cout.precision(3);
    cout << answer;

    return 0;
}

// 피드백) double 타입에 int가 저장되지 않도록 형변환 주의