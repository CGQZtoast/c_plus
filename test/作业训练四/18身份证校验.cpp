#include <iostream>
using namespace std;

int W[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
string Y = "10X987654321";

int main()
{
    string str;
    while (cin >> str && str != "-1")
    {
        int sum = 0;
        for (int i = 0; i < 17; i++)
            sum += (str[i] - '0') * W[i];
        sum %= 11;
        if (str[17] == Y[sum])
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}