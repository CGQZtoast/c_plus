#include <iostream>
using namespace std;

// 字符串的按位或运算
string operator|(string str1, string str2)
{
    string str;
    int n = str1.length();
    for (int i = 0; i < n; i++)
    {
        if (str1[i] == '1' || str2[i] == '1')
            str += '1';
        else
            str += '0';
    }
    return str;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string bit_num[n];
    for (int i = 0; i < n; i++)
        cin >> bit_num[i];

    string result;
    string temp;
    for (int i = 0; i < m; i++)
        temp += '1';

    for (int i = 0; i < n; i++)
    {
        result.clear();
        for (int i = 0; i < m; i++)
            result += '0';

        for (int j = 0; j < n; j++)
            if (j != i)
                result = result | bit_num[j];
        if(result == temp)
            break;
    }
    if (result == temp)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}