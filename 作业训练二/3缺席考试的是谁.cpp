#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;

    map<string, int> person;
    map<string, int>::iterator it;

    while (cin >> n && n != 0)
    {
        person.clear();
        string name;
        for (int i = 0; i < 2 * n - 1; i++)
        {
            cin >> name;
            if (!person[name])
                person[name] = 1;
            else
                person[name]++;
        }

        for (it = person.begin(); it != person.end(); it++)
            if (it->second % 2 == 1)
                cout << it->first << endl;
    }
    return 0;
}