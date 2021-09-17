#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int temp = 0;
        for (int j = i; j < n - 1; j++)
        {
            if (arr[j] < arr[j + 1])
                temp++;
            else
                break;
        }
        if (temp > ans)
            ans = temp;
    }
    cout << ans + 1 << endl;
}