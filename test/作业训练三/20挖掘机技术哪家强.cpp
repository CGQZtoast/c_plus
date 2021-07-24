#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, int> grade;
    map<int, int>::iterator it;

    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (!grade[a])
            grade[a] = b;
       else
            grade[a] += b;
    }

    int max = 0;
    for (it = grade.begin(); it != grade.end(); it++)
        if (it->second > max)
            max = it->second;
    for (it = grade.begin(); it != grade.end(); it++)
        if (it->second == max)
            cout << it->first << ' ' << it->second << endl;
}