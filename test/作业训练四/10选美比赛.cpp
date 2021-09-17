#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    
    int arr[n], temp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        temp[i] = arr[i];
    }
        
    sort(temp, temp + n, cmp);

    map<int, int> ans;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (!ans[temp[i]])
        {
            k++;
            ans[temp[i]] = k;
        }
    }

    for (int i = 0; i < n; i++)
        cout << ans[arr[i]] << ' ';

    return 0;
}