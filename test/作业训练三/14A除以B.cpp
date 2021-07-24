#include <iostream>
using namespace std;
int main()
{
    string str;
    char c;
    cin >> str >> c;

    int n = str.length();

    if (n == 1)
    {
        cout << (str[0] - '0') / (c - '0') << ' ' << (str[0] - '0') % (c - '0') << endl;
        return 0;
    }

    int temp, k;        
    if (str[0] >= c)
    {
        temp = 0;
        k = 0;
    }      
    else
    {
        temp = str[0] - '0';
        k = 1;
    }
        
    for (int i = k; i < n; i++)
    {
        int num = temp * 10 + str[i] - '0';
        cout << num / (c - '0');
        temp = num % (c - '0');
    }
    cout << ' ' << temp << endl;
}