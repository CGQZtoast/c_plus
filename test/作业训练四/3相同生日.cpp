#include <iostream>
#include <algorithm>
using namespace std;

struct people
{
    string id;
    int month;
    int day;
    int i; // 输入顺序
    bool flag = false; // 判断是否输出过
};

bool cmp(people a, people b)
{
    if (a.month != b.month)
        return a.month < b.month;
    if (a.day != b.day)
        return a.day < b.day;
    return a.i < b.i;
}

int main()
{
    int n;
    cin >> n;
    people person[n];
    for (int i = 0; i < n; i++)
    {
        cin >> person[i].id >> person[i].month >> person[i].day;
        person[i].i = i;
    }
        
    sort(person, person + n, cmp);

    for (int i = 0; i < n; i++)
    {
        if (person[i].flag == false)
        {
            person[i].flag = true;
            cout << person[i].month << ' ' << person[i].day << ' ' << person[i].id << ' ';
            for (int j = i; j < n; j++)
            {
                if (person[j].month == person[i].month && person[j].day == person[i].day && person[j].flag == false)
                {
                    person[j].flag = true;
                    cout << person[j].id << ' ';
                }
            }
            cout << endl;
        }
    }
}