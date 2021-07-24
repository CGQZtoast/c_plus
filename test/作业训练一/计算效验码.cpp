#include <iostream>
#include <map>
using namespace std;

bool check(string _num, int n)
{
    int len = _num.length();
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if(_num[i] >= '0' && _num[i] <= '9')
            sum += (_num[i] - '0');
        else
            sum += (_num[i] - 'a' + 10);
    }
        
    if (sum % n == 0)
        return true;
    else
        return false;
}

int main()
{
    map<int, char> m;
    m[10] = 'a';
    m[11] = 'b';
    m[12] = 'c';
    m[13] = 'd';
    m[14] = 'e';
    m[15] = 'f';

    int t;
    cin >> t;
    int b;
    string n;
    for (int i = 0; i < t; i++)
    {
        cin >> b >> n;
        string temp;
        for (int j = 0; j < b; j++)
        {
            temp = n;
            if (j < 10)
                temp += to_string(j);
            else
                temp += m[j];
            if (check(temp, b - 1))
            {
                int size = temp.length();
                cout << temp[size - 1] << endl;
                break;
            }
        }
    }
}