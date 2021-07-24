#include <iostream>
using namespace std;

void q_num(int n)
{
    int upright = 0;
    int level = 0;

    int num[n][n];
    int start = 0;
    if (n % 2 == 0)
        start = n / 2 - 1;
    else
        start = n / 2;

    int flag = 0; // 四种方向 1,2,3,4各对应一个方向
    int temp = 1; // temp步循环后更改方向 (每两次加一)
    int k = 0;
    int l = start, r = start;
    for (int i = 1; i <= n * n; i++)
    {
        num[l][r] = i;

        if (flag % 4 == 0)
        {
            upright = 0;
            level = 1;
            // cout << "right" << endl;
        }
        else if (flag % 4 == 1)
        {
            upright = 1;
            level = 0;
            // cout << "down" << endl;
        }
        else if (flag % 4 == 2)
        {
            upright = 0;
            level = -1;
            // cout << "left" << endl;
        }
        else
        {
            upright = -1;
            level = 0;
            // cout << "up" << endl;
        }

        r += level;
        l += upright;

        k++;
        if (k % temp == 0)
            flag++;
        if (k == temp * 2)
        {
            temp++;
            k = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << num[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    q_num(n);
}