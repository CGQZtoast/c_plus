#include <iostream>
using namespace std;

struct person
{
    int win = 0;
    int dogfall = 0;
    int lose = 0;
    int win_num[3] = {0, 0, 0};
    char max_()
    {
        int max = 0;
        max = win_num[0] >= win_num[1] ? win_num[0] : win_num[1];
        max = max >= win_num[2] ? max : win_num[2];
        if (max == win_num[2])
            return 'B';
        else if(max == win_num[0])
            return 'C';
        else
            return 'J';
    }
};

int main()
{
    int n;
    cin >> n;
    person p1, p2;

    char a, b;
    while (n--)
    {
        cin >> a >> b;
        if (a == b) //平局
        {
            p1.dogfall++;
            p2.dogfall++;
        }
        else if ((a == 'C' && b == 'J') || (a == 'J' && b == 'B') || (a == 'B' && b == 'C')) // a胜
        {
            p1.win++;
            p2.lose++;
            if (a == 'C')
                p1.win_num[0]++;
            else if (a == 'J')
                p1.win_num[1]++;
            else
                p1.win_num[2]++;
        }
        else // b胜
        {
            p2.win++;
            p1.lose++;
            if (b == 'C')
                p2.win_num[0]++;
            else if (b == 'J')
                p2.win_num[1]++;
            else
                p2.win_num[2]++;
        }
    }

    cout << p1.win << ' ' << p1.dogfall << ' ' << p1.lose << endl;
    cout << p2.win << ' ' << p2.dogfall << ' ' << p2.lose << endl;

    cout << p1.max_() << ' ' << p2.max_() << endl;
}