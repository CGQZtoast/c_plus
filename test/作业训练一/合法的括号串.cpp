#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        stack<char> demo;
        string temp;

        cin >> temp;

        int n = temp.length();
        demo.push(temp[0]);
        for (int i = 1; i < n; i++)
        {
            if (demo.empty())
                demo.push(temp[i]);
            else
            {
                if ((demo.top() == '<' && temp[i] == '>') || (demo.top() == '(' && temp[i] == ')') || (demo.top() == '[' && temp[i] == ']') || (demo.top() == '{' && temp[i] == '}'))
                    demo.pop();
                else
                    demo.push(temp[i]);
            }
        }

        if (demo.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}