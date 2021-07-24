#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        int arr[n];
        int sum = 0;
        float ave = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        ave = sum * 1.0 / n;

        float result = 0;
        for(int i = 0; i < n; i++)
        {
            result += (arr[i] - ave) * (arr[i] - ave);
        }
        result /= n * 1.0;
        result = int(result);
        cout << result << endl;
    }
}