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

    // A, B 각각 n장씩 보유
    int n;
    cin >> n;

    vector<bool> visited = vector<bool>(2*n+1, false);

    vector<int> arrA;
    vector<int> arrB;

    int elem;
    for (int i = 0; i < n; i++) {
        cin >> elem;
        arrB.push_back(elem);
        visited[elem] = true;
    }

    // 내림차순으로 arrB 정렬
    sort(arrB.begin(), arrB.end(), comp);

    // 남은 수로 arrA 채워
    // arrA는 오름차순으로 정렬됨
    for (int i = 1; i <= 2*n; i++) {
        if (!visited[i]) arrA.push_back(i);
    }

    // 점수가 최대가 되도록 arrA의 원소 배치

    // arrA에서 제일 큰 수 = 마지막 원소
    int left = 0;
    int right = arrA.size()-1;
    int cnt = 0; // A가 이기는 판의 수
    for (int i = 0; i < n; i++) {
        int a; // 이번 판에 A가 내는 수

        // arrB[i]가 남은 수 중 제일 큰 수보다 크다면 못 이김 
        // >>> 제일 작은 수 주고 그 판은 진다
        if (arrB[i] > arrA[right]) {
            a = arrA[left];
            left++;
        } else {
            a = arrA[right];
            right--;
        }

        if (a > arrB[i]) cnt++;
    }

    cout << cnt;
    
    return 0;
}