#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<char, string> num;
    num['0'] = "0178";
    num['1'] = "0134789";
    num['2'] = "28";
    num['3'] = "13789";
    num['4'] = "1489";
    num['5'] = "5689";
    num['6'] = "568";
    num['7'] = "013789";
    num['8'] = "0123456789";
    num['9'] = "1345789";

    while (1)
    {
        char arr[10];
        for (int i = 0; i < 10; i++)
        {
            cin >> arr[i];
            if (arr[0] == '-')
                return 0;
        }
            
        bool flag = true;
        for (int i = 0; i < 9; i++)
        {
            int cur = num[arr[i]].find(arr[i + 1]);
            if (cur == -1)
                flag = false;
        }
        if (flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

/*
0 -> 0 1 7 8
1 -> 0 1 3 4 7 8 9
2 -> 2 8
3 -> 1 3 7 8 9
4 -> 1 4 8 9
5 -> 5 6 8 9
6 -> 5 6 8
7 -> 0 1 3 7 8 9
8 -> 0 1 2 3 4 5 6 7 8 9
9 -> 1 3 4 5 7 8 9
*/