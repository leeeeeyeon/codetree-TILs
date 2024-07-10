#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<pair<int, pair<int, int>>> vpip;
typedef pair<int, pair<int, int>> pip;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// {숫자, {행, 열}}
vpip bfs(int r, int c, vvi &board, vvb &visited) {
    int n = board.size();
    queue<pair<int, int>> q;
    vpip ret;

    // 시작점 방문 처리
    visited[r][c] = true;
    q.push({r, c});

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // Index out of range
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            // 이미 방문한 경우
            if (visited[nx][ny]) continue;
            // 현재 칸에 적힌 숫자보다 큰 경우
            if (board[nx][ny] >= board[r][c]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
            ret.push_back({board[nx][ny], {nx, ny}});
        }
    }

    return ret;
}

// 숫자 큰 순 > 행 작은 순 > 열 작은 순으로 정렬
bool comp(pip a, pip b) {
    if (a.first == b.first) {
        if (a.second.first == b.second.first) return a.second.second < b.second.second;
        return a.second.first < b.second.first;
    }

    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; // 격자의 크기, 반복할 횟수
    cin >> n >> k;

    vvi board = vvi(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int r, c;
    cin >> r >> c;
    r--;
    c--;

    while (k--) {
        // visited 배열 초기화
        vvb visited = vvb(n, vector<bool>(n, false));

        // BFS로 갈 수 있는 칸의 리스트를 구한다
        vpip squares = bfs(r, c, board, visited);

        // 더 이상 새로 이동할 위치가 없다면 종료
        if (squares.empty()) break;

        // 숫자 큰 순 > 행 작은 순 > 열 작은 순으로 정렬
        sort(squares.begin(), squares.end(), comp);

        // 첫 번째 원소
        r = squares[0].second.first;
        c = squares[0].second.second;
    }
    
    cout << r+1 << ' ' << c+1;

    return 0;
}