#include <iostream>
#include <string>

using namespace std;

struct Info {
    string name;
    int level;

    Info() {
        this->name = "codetree";
        this->level = 10;
    }

    Info(string n, int l) {
        this->name = n;
        this->level = l;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string name;
    int level;
    cin >> name >> level;

    Info info1 = Info();
    Info info2 = Info(name, level);

    cout << "user " << info1.name << " lv " << info1.level << '\n';
    cout << "user " << info2.name << " lv " << info2.level << '\n';
    
    return 0;
}