#include <iostream>
using namespace std;
int main()
{
    string my_str;
    cin >> my_str;

    int len = my_str.length();
    // int arr[10];
    // for (int i = 0; i < 10; i++)
    //     arr[i] = 0;
    int arr[10] = {0};

    for (int i = 0; i < len; i++)
        arr[my_str[i] - '0']++;

    string str;
    while (cin >> str)
    {
        int n = str.length();
        bool flag = false;
        if (n == 5)
        {
            for (int i = str[0] - '0' + 1; i <= 5 ; i++)
            {
                if (arr[i] > 0 && arr[i + 1] > 0 && arr[i + 2] > 0 && arr[i + 3] > 0 && arr[i + 4] > 0)
                {
                    if (flag == false) 
                    {
                        cout << "YES ";
                        flag = true;
                    } 
                    else
                        cout << ' ';
                    cout << i << i + 1 << i + 2 << i + 3 << i + 4 ;
                }
            }
        }
        else
        {
            for (int i = str[0] - '0' + 1; i < 10; i++)
            {
                if (arr[i] >= n)
                {
                    if (flag == false)
                    {
                        cout << "YES ";
                        flag = true;
                    }     
                    else
                        cout << ' ';
                    for (int j = 0; j < n; j++)
                        cout << i;
                }
            }
        }
        if (flag == true)
            cout << endl;
        else  
            cout << "NO" << endl;
    }
    return 0;
}