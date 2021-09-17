#include <iostream>
using namespace std;
int main()
{
    int a[10] = {0};
    int temp;
    while (cin >> temp)
        a[temp]++;
    for (int i = 1; i < 10; i++)
        if (a[i] > 0)
        {
            cout << i;
            a[i]--;
            break;
        }
    for (int i = 0; i < 10; i++)
    {
        while (a[i]--)
            cout << i;
    }
}