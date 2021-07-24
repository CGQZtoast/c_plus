#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    map<int, int> num;
    int a, b;
    while (cin >> a >> b && (a != 0 || b != 0))
        num[a] = b;
    while (cin >> a >> b && (a != 0 || b != 0))
    {
        if (!num[a])
            num[a] = b;
        else
            num[a] += b;
    }

    map<int, int>::reverse_iterator it; // 反向迭代器
    for (it = num.rbegin(); it != num.rend(); it++)
    {
        if (it->second != 0)
            cout << it->first << ' ' << it->second << endl;
    }
    return 0;
}