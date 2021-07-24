#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string str;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        stringstream ss;
        ss << str;
        string temp, new_str;
        while (ss >> temp)
        {
            reverse(temp.begin(), temp.end());
            new_str = new_str + temp + ' ';
        }
        ss.clear();
        cout << new_str << endl;
    }
}