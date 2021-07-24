#include <iostream>

using namespace std;

int dfs(const string& str, const string& raw, int index=0) {  // 返回可能的情况数
    int n = str.length();
    if (index > n) {  // 边界条件
        return 0;
    }
    if (str[index] == '?') {
        int sum = 0, cnt = 1;
        for (int i = index + 1; i < n; i++) {
            (str[i] == '?') && (cnt *= 10);
        }
        sum += cnt * ('9' - raw[index]);
        sum += dfs(str, raw, index + 1);
        return sum;
    } else {
        if (str[index] == raw[index]) {
            return dfs(str, raw, index + 1);
        }
        if (str[index] > raw[index]) {
            int cnt = 1;
            for (int i = index + 1; i < n; i++) {
                (str[i] == '?') && (cnt *= 10);
            }
            return cnt;  // str[index] < raw[index]
        }
        return 0;
    }
}

int main() {
    string str, raw;
    while (cin >> str >> raw) {
        cout << dfs(str, raw) << endl;
    }
    return 0;
}
