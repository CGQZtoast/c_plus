#include <iostream>
using namespace std;
int main()
{
    int n, w;
    cin >> n >> w;
    int max = 0, min = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        if (sum > max)
            max = sum;
        if (sum < min)
            min = sum;
    }
    if (w - max + 1 + min >= 0)
        cout << w - max + 1 + min << endl;
    else
        cout << 0 << endl;
}