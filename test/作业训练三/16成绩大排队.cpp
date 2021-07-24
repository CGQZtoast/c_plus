#include <iostream>
#include <algorithm>
using namespace std;

struct student
{
    string name;
    string id;
    int grade;
};

bool cmp(student a, student b)
{
    return a.grade > b.grade;
}

int main()
{
    int n;
    cin >> n;
    student students[n];
    for (int i = 0; i < n; i++)
    {
        cin >> students[i].name >> students[i].id >> students[i].grade;
    }

    sort(students, students + n, cmp);

    cout << students[0].name << ' ' << students[0].id << endl;
    cout << students[n - 1].name << ' ' << students[n - 1].id << endl;
}