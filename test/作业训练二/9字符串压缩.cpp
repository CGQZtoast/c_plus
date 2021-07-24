#include <iostream>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    string str;
    cin >> str;

    int ans = 0;
    string temp1, temp2;

    ans += a;
    for (int i = 1; i < n; i++)
    {
        bool flag = false;
        temp1 = str.substr(0, i);
        for (int j = 1; j < n; j++)
        {
            temp2 = str.substr(i, n - j);
            int cur = temp1.find(temp2);
            if (cur != -1)
            {
                int len = temp2.length();
                if (len > b / a)
                {
                    ans += b;
                    flag = true;
                    i += (n - j - 1);
                    break;
                }
            }
        }
        if (flag == false)
            ans += a;
    }
    cout << ans;
}