#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[n][2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> arr[i][j];

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        if (i + 1 < n)
            temp = arr[i + 1][0];
        else
            temp = arr[i - 1][0];

        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (arr[j][0] * temp < 0)
                    break;
                count++;
            }
        }
        if (count == n - 1)
            break;
    }
    if (count == n - 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}