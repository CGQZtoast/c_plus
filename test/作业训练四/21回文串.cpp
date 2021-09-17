#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n = 0;
    while (cin >> n && n != 0)
    {
        string str;
        cin >> str;
        for (int i = 0; i < n; i++)
        {
            string temp = str.substr(i, n);
            string temp1 = temp;
            reverse(temp1.begin(), temp1.end());
            if (temp == temp1)
            {
                cout << i << endl;
                break;
            }
        }
    }
}