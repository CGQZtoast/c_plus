#include <iostream>
#include <math.h>
using namespace std;

long long int true_num(long long int x)
{
    string str_x = to_string(x);
    int n = str_x.length();
    for (int i = 0; i < n; i++)
    {
        if (str_x[i] > '8')
            str_x[i] -= 1;
        if (str_x[i] > '3')
            str_x[i] -= 1;
    }

    long long int true_num = 0, k = 0;
    for (int i = str_x.length() - 1; i >= 0; i--)
    {
        true_num += (str_x[i] - '0') * pow(10, k);
        k++;
    }
    return true_num;
}

long long int type8_to_10(long long int x)
{
    long long int type10_num = 0;
    long long int i = 0;
    while (x > 0)
    {
        long long int n = x % 10;
        type10_num += n * pow(8, i);
        x /= 10;
        i++;
    }
    return type10_num;
}

int main()
{
    long long int T;
    cin >> T;
    long long int n;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        cout << type8_to_10(true_num(n)) << endl;
    }
    return 0;
}