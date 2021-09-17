#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (arr[i] > arr[j])
                    ans++;
        cout << ans << endl;
    }
}