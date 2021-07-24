#include <iostream>
using namespace std;
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int len1 = str1.length();
    int len2 = str2.length();
    int count = 0;

    bool flag = true;
    for (int i = 0; i < len2; i++)
    {
        int cur = str1.find(str2[i]);
        if (cur != -1)
        {
            str1.erase(cur, 1);
            count++;
        }
        else
            flag = false;
    }

    if (flag == true)
        cout << "Yes" << ' ' << len1 - len2 << endl;
    else
        cout << "No" << ' ' << len2 - count << endl;
}