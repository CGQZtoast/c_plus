#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct team
{
    string name;
    int win_count;
    int count;
    team()
    {
        name = "null";
        win_count = 0;
        count = 0;
    }
    team(string t_name)
    {
        name = t_name;
        win_count = 0;
        count = 0;
    }
};

bool cmp(team a, team b);

vector<team> competition(vector<team> teams, vector<string> teams_cmpt, int temp_grade1, int temp_grade2);

int main()
{
    int T;
    cin >> T;

    vector<team> teams;
    vector<string> teams_cmpt;

    string temp_name1, blank, temp_name2; 
    int temp_grade1, temp_grade2;

    for(int i = 0; i < T; i++)
    {
        teams.clear();
        for(int j = 0; j < 12; j++)
        {
            teams_cmpt.clear();

            cin >> temp_name1 >> temp_grade1 >> blank >> temp_grade2 >> temp_name2;

            teams_cmpt.push_back(temp_name1);
            teams_cmpt.push_back(temp_name2);

            teams = competition(teams, teams_cmpt, temp_grade1, temp_grade2);
        }

        sort(teams.begin(), teams.end(), cmp);

        cout << teams[0].name << ' ' << teams[1].name << endl;
    }
    return 0;
}

bool cmp(team a, team b)
{
    if(a.count != b.count)
        return a.count > b.count;
    else
        return a.win_count > b.win_count;
}

vector<team> competition(vector<team> teams, vector<string> teams_cmpt, int temp_grade1, int temp_grade2)
{
    vector<team>::iterator temp;
    //检查所有队伍中是否存在这两队
    int flag = 0;
    for(temp = teams.begin(); temp != teams.end(); temp++)
    { 
        if (temp->name == teams_cmpt[0])
            flag = 1; break;
    }
    if(flag==0)
    { 
        teams.push_back(team(teams_cmpt[0]));
    }
    flag = 0;
    for(temp = teams.begin(); temp != teams.end(); temp++)
    { 
        if (temp->name == teams_cmpt[1])
            flag = 1; break;
    }
    if(flag==0) 
        teams.push_back(team(teams_cmpt[1]));

    if (temp_grade1 == temp_grade2) //两队进球数相同，都得1分
    {
        for (temp = teams.begin(); temp != teams.end(); temp++)
        {
            if (temp->name == teams_cmpt[0]) //第一队
                temp->count += 1;
            else if (temp->name == teams_cmpt[1]) //第二队
                temp->count += 1;
        }
    }
    else if (temp_grade1 > temp_grade2) //第一队获胜，第一队得三分
    {
        for (temp = teams.begin(); temp != teams.end(); temp++)
        {
            if (temp->name == teams_cmpt[0]) //第一队
            {
                temp->count += 3;
                temp->win_count += (temp_grade1 - temp_grade2); //净胜球数
            }
            else if (temp->name == teams_cmpt[1]) //第二队
                temp->win_count -= (temp_grade1 - temp_grade2);
        }
    }
    else //第二队获胜，第二队得三分
    {
        for (temp = teams.begin(); temp != teams.end(); temp++)
        {
            if (temp->name == teams_cmpt[0]) //第一队
                temp->win_count -= (temp_grade2 - temp_grade1);
            else if (temp->name == teams_cmpt[1]) //第二队
            {
                temp->count += 3;
                temp->win_count += (temp_grade2 - temp_grade1); //净胜球数
            }
        }
    }
    return teams;
}
