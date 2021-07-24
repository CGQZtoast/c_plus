#include <iostream>
#include <algorithm>
using namespace std;

struct people
{
    int num;
    int s;
    int v;
};

bool cmp(people a, people b)
{
    if (a.s != b.s)
        return a.s < b.s;
    return a.v > b.v;
}

int main()
{
    int n, k;
    cin >> n >> k;

    people *person = new people[n];
    for (int i = 0; i < n; i++)
    {
        cin >> person[i].s;
        person[i].num = i + 1;
    }
    for (int i = 0; i < n; i++)
        cin >> person[i].v;

    sort(person, person + n, cmp);

    int maxV = person[0].v, i = 0;
    while (person[i].num != k)
    {
        if (person[i].v > maxV)
            maxV = person[i].v;
        i++;
    }
    if (person[i].v > maxV)
            maxV = person[i].v;

    int minV = person[i].v, count = 0;
    for (int j = i + 1; j < n; j++)
    {
        if (person[j].v >= maxV && person[j].s > person[i].s)
            count++;
        if (person[j].v < minV)
            minV= person[j].v;
    }

    for (int j = 0; j < i; j++)
    {
        if (person[j].v <= minV && person[j].s < person[i].s)
            count++;
    }
        
    cout << n - count << endl;
}