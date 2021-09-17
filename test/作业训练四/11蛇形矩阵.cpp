#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    int a = 1, b = 1, k = 0;
    for (int i = 1; i <= n; i++)
    {
        b = a;
        a = a + i;
        k = i + 1;
        for (int j = i; j <= n; j++)
        {
            cout << b << ' ';
            b += k;
            k++;
        }
        cout << endl;
    }
    
    return 0;
}