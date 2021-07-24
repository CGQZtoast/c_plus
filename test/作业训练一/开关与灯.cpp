/*  
    由于 1 <= m <= 2000
    应该用字符串来储存和判断
*/

#include <iostream>
#include <math.h>
using namespace std;

int type2_to_10(int type2_num, int m)
{
    int type10_num = 0;
    for (int i = 0; i < m; i++)
    {
        type10_num += type2_num % 10 * pow(2, i);
        type2_num /= 10;
    }
    return type10_num;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int bit_arr[n];
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> bit_arr[i];
        arr[i] = type2_to_10(bit_arr[i], m);
    }

    int result;
    for (int i = 0; i < n; i++)
    {
        result = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
                result = result | arr[j];
        }
        if (result == type2_to_10((pow(10, m + 1) - 1) / 9, m))
            break;
    }
    if (result == type2_to_10((pow(10, m + 1) - 1) / 9, m))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}