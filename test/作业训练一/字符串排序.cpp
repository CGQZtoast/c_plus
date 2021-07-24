#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct str_int
{
    string str;
    int i;
    int count;
};


int count_(string str, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        char temp1 = str[i];
        for(int j = i; j < n; j++)
        {
            char temp2 = str[j];
            if(temp1 > temp2)
                count++;
        }
    }
    return count;
}

bool cmp(str_int a, str_int b)
{
    if(a.count != b.count)
        return a.count < b.count;
    return a.i < b.i;
}

int main()
{
    int m, n;
    cin >> n >> m;

    str_int str[m];
    for(int i = 0; i < m; i++)
    {
        cin >> str[i].str;
        str[i].i = i;
        str[i].count = count_(str[i].str, n);
    }

    sort(str, str + m, cmp);

    for(int i = 0; i < m; i++)
    {
        cout << str[i].str << endl;
    }

}