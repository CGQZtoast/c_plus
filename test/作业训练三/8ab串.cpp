#include <iostream>
using namespace std;

int F[3][5001] = {0};

int main() {
    string str; cin >> str;
    int length = str.size();

    for (int i = 1; i <= length; i++) {  // 状态 A
        F[0][i] = F[0][i-1] + (str[i-1] == 'a');
    }

    for (int i = 1; i <= length; i++) {  // 状态 B
        if (str[i-1] == 'b') {
            F[1][i] = F[1][i-1] + 1;
        } else {
            F[1][i] = max(F[1][i-1], F[0][i]);
        }
    }

    for (int i = 1; i <= length; i++) {  // 状态 C
        if (str[i-1] == 'a') {
            F[2][i] = F[2][i-1] + 1;
        } else {
            F[2][i] = max(F[2][i-1], F[1][i]);
        }
    }

    cout << F[2][length] << endl;
    return 0;
}
