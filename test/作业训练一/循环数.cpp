#include <iostream>
#include <algorithm>
using namespace std;

string multip_str(string str, int n)
{
    int size = str.length();
    string new_str;
    int temp = 0;
    for(int i = size - 1; i >= 0; i--)
    {
        new_str += to_string(((str[i] - '0') * n + temp) % 10);
        temp = ((str[i] - '0') * n + temp) / 10;
    }
    reverse(new_str.begin(), new_str.end());
    return new_str;
}

string shift(string str, int n)
{
    string new_str;
    int size = str.length();
    new_str = str.substr(size - n, n) + str.substr(0, size - n);
    return new_str;
}

int main()
{
    string str;
    cin >> str;
    int count = 1;
    int n = str.length();
    for(int i = 2; i <= n; i++)
    {    
        for(int j = 1; j <= n; j++)
            if(multip_str(str, i) == shift(str, j))
            {
                count++;  
                break;
            }          
    }
    if(count == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}