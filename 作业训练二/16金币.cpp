#include <iostream>
using namespace std;
int main()
{
    int day;
    while (cin >> day)
    {
        int sum = 0;
        int flag = 1;
        int count = flag;
        for (int i = 0; i < day; i++)
        { 
            if (count > 0)
            {
                sum += flag;
                count--;
                if (count == 0)
                {
                    flag++;
                    count = flag;
                }
            }   
        }
        cout << day << ' ' << sum << endl;
    }
}