#include <iostream>
#include <algorithm>
using namespace std;

string operator+(string x, string y)
{
    int len_x = x.length();
    int len_y = y.length();

    long long int num_1 = 0;
    long long int temp_1 = 1;
    for (int i = len_x - 1; i >= 0; i--)
    {
        num_1 += (x[i] - 'a') * temp_1;
        temp_1 *= 26;
    }
    long long int num_2 = 0;
    long long int temp_2 = 1;
    for (int i = len_y - 1; i >= 0; i--)
    {
        num_2 += (y[i] - 'a') * temp_2;
        temp_2 *= 26;
    }

    long long int num = num_1 + num_2;

    string result;
    while (num != 0)
    {
        result += (num % 26 + 'a');
        num /= 26;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string x, y;
        cin >> x >> y;
        cout << x + y << endl;
    }
}