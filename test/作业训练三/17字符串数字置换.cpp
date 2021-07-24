#include <iostream>
#include <map>
using namespace std;
int main()
{
    string str;
    getline(cin, str, '\n');

    map<char, string> num;
    {
        num['0'] = "(Zero)";
        num['1'] = "(One)";
        num['2'] = "(Two)";
        num['3'] = "(Three)";
        num['4'] = "(Four)";
        num['5'] = "(Five)";
        num['6'] = "(Six)";
        num['7'] = "(Seven)";
        num['8'] = "(Eight)";
        num['9'] = "(Nine)";
    }

    map<char, int> count;
    for (int i = 0; i < 10; i++)
        count['0' + i] = 0;

    int n = str.length();
    string new_str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            new_str += num[str[i]];
            count[str[i]]++;
        }
        else
            new_str += str[i];
    }
    cout << new_str << endl;
    for (int i = 0; i < 10; i++)
        cout << count['0' + i] << ' ';
}