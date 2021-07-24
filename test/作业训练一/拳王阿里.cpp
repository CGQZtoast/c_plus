#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> week;
    week["monday"] = 1;
    week["tuesday"] = 2;
    week["wednesday"] = 3;
    week["thursday"] = 4;
    week["friday"] = 5;
    week["saturday"] = 6;
    week["sunday"] = 7;

    int T;
    cin >> T;
    string S, E;
    int L, R;
    for (int i = 0; i < T; i++)
    {
        cin >> S >> E;
        cin >> L >> R;

        int first_day = week[S];
        int last_day = week[E];

        int day_count = last_day - first_day + 1 > 0 ? last_day - first_day + 1 : last_day - first_day + 1 + 7;

        int count = 0;
        int k = 0;
        while (day_count + 7 * k <= R)
        {
            if (L <= day_count + 7 * k && day_count + 7 * k <= R)
                count++;
            k++;
        }

        if (count == 0)
            cout << "impossible" << endl;
        else if (count > 1)
            cout << "many" << endl;
        else
            cout << day_count + 7 * (k - 1) << endl;
    }
}