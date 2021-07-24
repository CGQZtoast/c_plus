#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int high[n];
    for (int i = 0; i < n; i++)
        cin >> high[i];

    int ans[n];
    for (int i = 0; i < n; i++)
        ans[i] = 0;
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (high[j] >= high[i])
                if (ans[j] + 1 > ans[i])
                    ans[i] = ans[j] + 1;
        max = max > ans[i] ? max : ans[i];
    }

    cout << max + 1 << endl;
    return 0;
}