#include <iostream>
#include <sstream>
#include <stack>
using namespace std;
int main()
{
    string str;
    stringstream ss;
    stack<string> new_str;
    while(getline(cin, str, '\n'))
    {
        ss << str;
        string temp;
        while(ss >> temp)
            new_str.push(temp);
        while(!new_str.empty())
        {
            cout << new_str.top() << ' ';
            new_str.pop();
        }
        cout << endl;
        ss.clear();
    }

}