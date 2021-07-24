#include <iostream>
#include <math.h>
using namespace std;

string true_num(string x)
{
    int n = x.length();
    for (int i = 0; i < n; i++)
    {
        if (x[i] > '8')
            x[i] -= 1;
        if (x[i] > '3')
            x[i] -= 1;
    }
    return x;
}

int type8_to_10(string x)
{
    int type10_num = 0;
    int n = x.length();
    for (int i = 0; i < n; i++)
    {
        type10_num += (x[i] - '0') * pow(8, n - i - 1);
    }
    return type10_num;
}

int main()
{
    int T;
    cin >> T;
    string n;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        cout << type8_to_10(true_num(n)) << endl;
    }
    return 0;
}
