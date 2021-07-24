#include <iostream>
using namespace std;
int main()
{
    int n;
    int k = 1;
    while (cin >> n && n != 0)
    {
        string name[n];
        for (int i = 0; i < n; i++)
            cin >> name[i];

        string new_name[n];
        int pre = 0;
        int cur = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                new_name[pre] = name[i];
                pre++;
            }
            else
            {
                new_name[cur] = name[i];
                cur--;
            }
        }
        cout << "set-" << k << endl;
        k++;
        for (int i = 0; i < n; i++)
        {
            cout << new_name[i] << endl;
        }
    }
}