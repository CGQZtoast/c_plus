#include <iostream>
using namespace std;

int sum(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if(n % i == 0)
            sum += i;
    }
    return sum;
}

int main()
{
    int m, n;
    while (cin >> m >> n && m > 0 && n > 0)
    {
        if (sum(m) == n && sum(n) == m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}