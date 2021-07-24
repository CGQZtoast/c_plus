#include <bits/stdc++.h>
using namespace std;

struct pp
{
    string name;
    int point;
    int win;
};

int num(string s, pp now[5], int nowt)
{
    for (int i = 1; i <= nowt; i++)
    {
        if (now[i].name == s)
            return i;
    }
    return nowt + 1;
}
bool cmp(pp a, pp b)
{
    if (a.point > b.point)
        return 1;
    if (a.point < b.point)
        return 0;
    if (a.win >= b.win)
        return 1;
    return 0;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        pp now[5];
        for (int i = 1; i <= 4; i++)
        {
            now[i].point = 0;
            now[i].win = 0;
        }
        string s1, s2, ss;
        int p1, p2, nowteam = 0;
        for (int i = 1; i <= 12; i++)
        {
            cin >> s1 >> p1 >> ss >> p2 >> s2;
            int t1 = num(s1, now, nowteam);
            if (t1 > nowteam)
                nowteam++;
            int t2 = num(s2, now, nowteam);
            if (t2 > nowteam)
                nowteam++;
            now[t1].name = s1;
            now[t2].name = s2;
            now[t1].win += p1 - p2;
            now[t2].win += p2 - p1;
            if (p1 > p2)
                now[t1].point += 3;
            if (p1 == p2)
            {
                now[t1].point++;
                now[t2].point++;
            }
            if (p2 > p1)
                now[t2].point += 3;
        }
        sort(now + 1, now + 5, cmp);
        cout << now[1].name << " " << now[2].name << endl;
    }
    return 0;
}
