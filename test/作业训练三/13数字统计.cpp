#include <iostream>
#include <map>
using namespace std;
int main()
{
    string str;
    cin >> str;

    map<char, int> count;

    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (!count[str[i]])
            count[str[i]] = 1;
        else
            count[str[i]]++;
    }

    map<char, int>::iterator it;
    for (it = count.begin(); it != count.end(); it++)
        cout << it->first << ':' << it->second << endl; 
}
