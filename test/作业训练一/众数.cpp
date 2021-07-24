
#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
            
        int m1 = 0, m2 = 0, x = a[0];
        for (int i = 0; i < n; i++)
        {
            m2 = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] == a[j])
                    m2++;
                if (a[i] != a[j])
                    break;
            }
            if (m1 < m2)
            {
                m1 = m2;
                x = a[i];
            }
        }
        cout << x << endl;
    }
    return 0;
}
