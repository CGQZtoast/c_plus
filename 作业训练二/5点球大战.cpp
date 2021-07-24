#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        string str, result;
        string r1,r2;
        int win1 = 0, win2 = 0;
        for (int i = 0; i < n; i++)
        {
            getchar();
            getline(cin , str, '\n');
            result = str.substr(str.length() - 1 - 6, str.length() - 1);
            if (i % 2 == 0)
            {
                if (result == "no good")
                    r1 += 'X';
                else
                {
                    win1++;
                    r1 += 'O';
                }
            }
            else
            {
                if (result == "no good")
                    r2 += 'X';
                else
                {
                    win2++;
                    r2 += 'O';
                }
            }
        }
        if (n % 2 == 1)
            r2 += '-';
        for (int i = 0; i < (n + 1) / 2; i++)
            cout << i + 1 << ' ';
        cout << "Score" << endl;
        for (int i = 0; i < (n + 1) / 2; i++)
            cout << r1[i] << ' ';
        cout << win1 << endl;
        for (int i = 0; i < (n + 1) / 2; i++)
            cout << r2[i] << ' ';
        cout << win2 << endl;
    }
}