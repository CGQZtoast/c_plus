#include <iostream>
#include <map>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += str[i] - '0';

    map<char, string> num;
    {
        num['0'] = "ling";
        num['1'] = "yi";
        num['2'] = "er";
        num['3'] = "san";
        num['4'] = "si";
        num['5'] = "wu";
        num['6'] = "liu";
        num['7'] = "qi";
        num['8'] = "ba";
        num['9'] = "jiu";
    }

    string ans = to_string(sum);
    int len = ans.length();
    for (int i = 0; i < len; i++)
        cout << num[ans[i]] << ' ';
}