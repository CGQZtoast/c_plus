#include <iostream>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char c;
    stack<char> temp;
    for (int i = 0; i < n; i++)
    {
        while(scanf("%1s", &c) && c != '\n')
        //cout << c;
        {
            if(c != ' ' || c != '\n')
            temp.push(c);
        else if(c == ' ')
            while(!temp.empty())
            {
                cout << temp.top();
                temp.pop();
            }
        else
            break;
        }
        
    }
}