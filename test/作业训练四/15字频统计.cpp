#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        string str;
        cin >> str;

        int num1 = 0, num2 = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (str[i] == 'a' && str[i + 1] == 'b')
                num1++;
            if (str[i] == 'b' && str[i + 1] == 'a')
                num2++;
        }
        cout << num1 - num2 << endl;
    }
}