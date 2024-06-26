#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

vector<vector<pii>> block1 = {
    {{0,0}, {1,0}, {1,1}},
    {{0,0}, {0,1}, {1,1}},
    {{0,1}, {1,1}, {1,0}},
    {{0,0}, {0,1}, {1,0}}
};

vector<pii> block2 = {{0,0}, {0,1}, {0,2}};

vector<pii> block3 = {{0,0}, {1,0}, {2,0}};


int main() {
    int n, m;
    cin >> n >> m;

    vvi board = vvi(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // Block 1
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Index out of range
            if(i+1 >= n || j+1 >= m) continue;

            for (int k = 0; k < 4; k++) {
                int sum = 0;
                for (auto elem : block1[k]) {
                    sum += board[i + elem.first][j + elem.second];
                }

                if (sum > mx) mx = sum;
            }
        }
    }

    // Block 2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j+2 >= m) continue;

            int sum = 0;
            for (auto elem : block2) {
                sum += board[i+elem.first][j+elem.second];
            }

            if (sum > mx) mx = sum;
        }
    }

    // Block 3
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i+2 >= n) continue;

            int sum = 0;
            for (auto elem : block3) {
                sum += board[i+elem.first][j+elem.second];
            }

            if (sum > mx) mx = sum;
        }
    }

    cout << mx;

    return 0;
}