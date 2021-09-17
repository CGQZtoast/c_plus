#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bool a = false, b = false; // 前一天是否去做运动或者编写程序
    int ans = 0;               // 休息天数
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0) // 健身房不开放，互联网上也没有竞赛
        {
            ans++;
            a = false;
            b = false;
        }
        else if (arr[i] == 1) // 健身房不开放，但互联网上有竞赛
        {
            if (b == true) // 前一天编写程序
            {
                ans++;
                a = false;
                b = false;
            }
            else
            {
                a = false;
                b = true;
            }
        }
        else if (arr[i] == 2) // 健身房开放，但互联网上没有竞赛
        {
            if (a == true) // 前一天去做运动
            {
                ans++;
                a = false;
                b = false;
            }
            else
            {
                a = true;
                b = false;
            }
        }
        else // 健身房开放，互联网上也有竞赛 ******
        {
            if (a == true) // 前一天去做运动
            {
                if (i + 1 < n && arr[i + 1] == 1)
                {
                    ans++;
                    a = false;
                    b = false;
                }
                else
                {
                    a = false;
                    b = true;
                }
            }
            else if (b == true) // 前一天编写程序
            {
                if (i + 1 < n && arr[i + 1] == 2)
                {
                    ans++;
                    a = false;
                    b = false;
                }
                else
                {
                    a = true;
                    b = false;
                }
            }
            else // 前一天休息
            {
                if (i + 1 < n)
                {
                    if (arr[i + 1] == 2) // 后一天健身房开放，但互联网上没有竞赛
                    {
                        a = false;
                        b = true;
                    }
                    else
                    {
                        a = true;
                        b = false;
                    }
                }
            }
        }

        // test
        if (a == true)
            cout << "sport" << endl;
        else if (b == true)
            cout << "write" << endl;
        else
            cout << "rest" << endl;
    }

    cout << ans << endl;
    return 0;
}
