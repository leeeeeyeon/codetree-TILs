#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;

struct cmp {
    bool operator()(ll a, ll b) {
        return abs(a) > abs(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    priority_queue<ll, vector<ll>, cmp> pq;
    while (n--) {
        ll x;
        cin >> x;

        if (x == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }

    return 0;
}