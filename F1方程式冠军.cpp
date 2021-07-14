#include <iostream>
#include <algorithm>
using namespace std;

struct team
{
    string name;
    int grade;
    int win_count[100];
    team()
    {
        name = "";
        grade = 0;
        for (int i = 0; i < 100; i++)
            win_count[i] = 0;
    }
    team(string t_name)
    {
        name = t_name;
        grade = 0;
        for (int i = 0; i < 100; i++)
            win_count[i] = 0;
    }
};

bool cmp_1(team a, team b)
{
    if (a.grade != b.grade)
        return a.grade > b.grade;
    else
    {
        for (int i = 0; i < 100; i++)
            if (a.win_count[i] != b.win_count[i])
                return a.win_count[i] > b.win_count[i];
    }
    return true;
}

bool cmp_2(team a, team b)
{
    if (a.win_count[0] != b.win_count[0])
        return a.win_count[0] > b.win_count[0];
    else
        return cmp_1(a, b);
}

int grade[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int main()
{
    team teams[100];

    int t;
    cin >> t;
    int num = 0;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        string str;
        for (int j = 0; j < n; j++)
        {
            cin >> str;
            if (num == 0)
            {
                teams[0] = team(str);
                if(j < 10)
                    teams[0].grade += grade[j];
                teams[0].win_count[j]++;
                num++;
                continue;
            }
            for (int k = 0; k < num; k++)
            {
                if(k == num - 1 && teams[k].name != str)
                {
                    teams[num] = team(str);
                    num++;
                }
                if (teams[k].name == str)
                {
                    if(j < 10)
                        teams[k].grade += grade[j];
                    teams[k].win_count[j]++;
                    break;
                }
            }
        }
    }

    sort(teams, teams + num, cmp_1);
    cout << teams[0].name << endl;
    sort(teams, teams + num, cmp_2);
    cout << teams[0].name << endl;
}