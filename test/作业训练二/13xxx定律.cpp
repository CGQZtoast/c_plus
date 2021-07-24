#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        int count = 0;
        while (n != 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else
                n = (3 * n + 1) / 2;
            count++;
        }
        cout << count << endl;
    }
}