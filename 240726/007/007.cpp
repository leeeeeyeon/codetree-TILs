#include <iostream>
#include <string>

using namespace std;

struct Info {
    string secretCode;
    char meetingPoint;
    int time;

    Info(string sc, char mp, int t) {
        this->secretCode = sc;
        this->meetingPoint = mp;
        this->time = t;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string sc;
    char mp;
    int t;
    cin >> sc >> mp >> t;

    Info info = Info(sc, mp, t);

    cout << "secret code : " << info.secretCode << '\n';
    cout << "meeting point : " << info.meetingPoint << '\n';
    cout << "time : " << info.time << '\n';

    return 0;
}