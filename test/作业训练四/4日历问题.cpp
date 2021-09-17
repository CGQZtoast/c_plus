// 2000年1月1日 星期六

#include <iostream>
#include <map>
using namespace std;

int arr1[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int arr2[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

map<int, string> weekends;
int main()
{
    weekends[0] = "Saturday";
    weekends[1] = "Sunday";
    weekends[2] = "Monday";
    weekends[3] = "Tuesday";
    weekends[4] = "Wednesday";
    weekends[5] = "Thursday";
    weekends[6] = "Friday";

    int days;
    while (cin >> days && days != -1)
    {
        int temp = days + 1;
        int year = 2000;
        bool flag = false; // 判断是闰年还是平年
        // 判断年份
        for (int i = 2000; temp > 0; i++)
        {
            int num = 0;
            // 判断一年有多少天
            // 闰年
            if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
            {
                num = 366;
            }
            // 平年
            else
                num = 365;

            if (temp <= num)
            {
                if (num == 366)
                    flag = true;
                year = i;
                break;
            }
            else
                temp -= num;
        }

        // 判断月份
        int month = 1;
        // 闰年
        if (flag == true)
            for (int i = 0; i < 12; i++)
            {
                if (temp <= arr1[i])
                {
                    month = i + 1;
                    break;
                }
                else
                    temp -= arr1[i];
            }
        // 平年
        else
            for (int i = 0; i < 12; i++)
            {
                if (temp <= arr2[i])
                {
                    month = i + 1;
                    break;
                }
                else
                    temp -= arr2[i];
            }

        // 判断日期
        int day = 1;
        if (temp != 0)
            day = temp;
        else
        {
            if (flag == true)
                day = arr1[month];
            else
                day = arr2[month];
        }

        // 判断星期
        int week = days % 7;

        cout << year << '-';
        if (month < 10)
            cout << '0';
        cout << month << '-';
        if (day < 10)
            cout << '0';
        cout << day << ' ';
        cout << weekends[week] << endl;
    }
}
