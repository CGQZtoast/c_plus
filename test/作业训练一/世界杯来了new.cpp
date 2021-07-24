#include <iostream>
#include <algorithm>
using namespace std;

struct team
{
    string name;
    int grade;
    int win_count;
    int count;
    team()
    {
        name = "";
        grade = 0;
        win_count = 0;
        count = 0;
    }
    team(string t_name)
    {
        name = t_name;
        grade = 0;
        win_count = 0;
        count = 0;
    }
};

bool cmp(team a, team b)
{
    if (a.grade != b.grade)
        return a.grade > b.grade;
    else
    {
        if (a.win_count != b.win_count)
            return a.win_count > b.win_count;
        else
            return a.count > b.count;
    }
}

int main()
{
    int n;
    cin >> n;
    team teams[n];
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        teams[i] = team(temp);
    }

    int num = n * (n - 1) / 2;
    string team1, team2;
    char grade1, grade2;
    for (int i = 0; i < num; i++)
    {
        getchar();
        getline(cin, team1, '-');
        getline(cin, team2, ' ');
        grade1 = getchar();
        getchar();
        grade2 = getchar();

        if (grade1 > grade2)
        {
            for (int j = 0; j < n; j++)
            {
                if (teams[j].name == team1)
                {
                    teams[j].grade += 3;
                    teams[j].win_count += grade1 - grade2;
                    teams[j].count += grade1;
                }
                if (teams[j].name == team2)
                {
                    teams[j].win_count += grade2 - grade1;
                    teams[j].count += grade2;
                }
            }
        }
        else if (grade1 == grade2)
        {
            for (int j = 0; j < n; j++)
            {
                if (teams[j].name == team1)
                {
                    teams[j].grade++;
                    teams[j].count += grade1;
                }
                if (teams[j].name == team2)
                {
                    teams[j].grade++;
                    teams[j].count += grade2;
                }
            }
        }
        else if (grade1 < grade2)
        {
            for (int j = 0; j < n; j++)
            {
                if (teams[j].name == team1)
                {
                    teams[j].win_count += grade1 - grade2;
                    teams[j].count += grade1;
                }
                if (teams[j].name == team2)
                {
                    teams[j].grade += 3;
                    teams[j].win_count += grade2 - grade1;
                    teams[j].count += 2;
                }
            }
        }
    }

    sort(teams, teams + n, cmp);

    string win_team[n / 2];
    for (int i = 0; i < n / 2; i++)
        win_team[i] = teams[i].name;

    sort(win_team, win_team + n / 2);

    for (int i = 0; i < n / 2; i++)
        cout << win_team[i] << endl;
}