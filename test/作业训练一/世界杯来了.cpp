/*
    只考虑比分的情况（各队最终比分不同）
*/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    // 参赛队伍数
    int n;
    cin >> n;

    map<string, int> teams;
    string temp;

    string team_name[n];

    // 队伍名
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        team_name[i] = temp;
        teams[temp] = 0;
    }

    // 比分情况
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
            teams[team1] += 3;
        else if (grade1 == grade2)
        {
            teams[team1] += 1;
            teams[team2] += 1;
        }
        else if (grade1 < grade2)
            teams[team2] += 3;
    }

    // 最终分数情况
    int grade[n];
    for (int i = 0; i < n; i++)
        grade[i] = teams[team_name[i]];

    map<int, string> cope;
    for (int i = 0; i < n; i++)
        cope[grade[i]] = team_name[i];

    // 分数排序
    sort(grade, grade + n);

    // 获胜队伍
    string win_team[n / 2];
    for (int i = 0; i < n / 2; i++)
        win_team[i] = cope[grade[n - 1 - i]];

    // 获胜队伍排序
    sort(win_team, win_team + n / 2);

    for (int i = 0; i < n / 2; i++)
        cout << win_team[i] << endl;
}