#include <iostream>
#include <vector>
using namespace std;

int main()
{ //: T5-8
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        vector<int> sum(n);
        for (int i = n - 1; i >= 0; i--)
        {
            sum[i] = arr[i];
            if (i + arr[i] < n)
            {
                sum[i] += sum[i + arr[i]];
            }
            ans = max(ans, sum[i]);
        }
        cout << ans << endl;
    }
    return 0;
}