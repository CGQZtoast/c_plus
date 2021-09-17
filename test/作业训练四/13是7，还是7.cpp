#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 7 == 0) // 7的倍数
        {
            cout << i << endl;
            continue;
        }
        int k = i;
        bool flag = false;
        while (k > 0)
        {
            if (k % 10 == 7)
            {
                flag = true;
                break;
            }  
            k /= 10;
        } 
        if (flag == true)
            cout << i << endl;  
    }
}