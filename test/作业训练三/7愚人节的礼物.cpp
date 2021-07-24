#include <iostream>
using namespace std;

void unpack(string str) {
    int cnt = 0;
    for (char ch : str) {
        if (ch == '(') {
            cnt += 1;
        } else if (ch == ')') {
            cnt -= 1;
        } else {
            cout << cnt << endl;
            return;
        }
    }
}

int main() {
    string str;
    while (cin >> str) {
        unpack(str);
    }
    return 0;
}