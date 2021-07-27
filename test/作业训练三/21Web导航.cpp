#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<string> pre;                   // 前向堆栈
    stack<string> next;                  // 后向堆栈
    string now = "http://www.game.org/"; // 当前页

    string str; // 命令
    while (cin >> str && str != "QUIT")
    {
        if (str == "VISIT")
        {
            string temp;
            cin >> temp;
            next.push(now);
            now = temp;
            while (!pre.empty())
                pre.pop();
            cout << now << endl;
        }
        else if (str == "FORWARD")
        {
            if (!pre.empty())
            {
                next.push(now);
                now = pre.top();
                pre.pop();
                cout << now << endl;
            }
            else
                cout << "Ignored" << endl;
        }
        else // BAKE
        {
            if (!next.empty())
            {
                pre.push(now);
                now = next.top();
                next.pop();
                cout << now << endl;
            }
            else
                cout << "Ignored" << endl;
        }
    }
}