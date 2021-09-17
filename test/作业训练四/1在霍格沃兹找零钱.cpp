#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int price1[3];
    int price2[3];
    scanf("%d.%d.%d", &price1[0], &price1[1], &price1[2]);
    scanf("%d.%d.%d", &price2[0], &price2[1], &price2[2]);

    int sum1 = 0, sum2 = 0;
    sum1 = price1[0]*17*29 + price1[1]*29 + price1[2];
    sum2 = price2[0]*17*29 + price2[1]*29 + price2[2];

    int ans = sum2 - sum1;
    if (ans < 0)
    {
        cout << '-';
        ans *= -1;
    }
    cout << ans / 17 / 29 << '.';
    ans -= ans / 17 / 29 * 17 * 29;
    cout << ans / 29 << '.';
    ans -= ans / 29 * 29;
    cout << ans << endl;
}