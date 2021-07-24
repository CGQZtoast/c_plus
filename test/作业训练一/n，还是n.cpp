#include <iostream>
using namespace std;

bool is_have_n(int x, int n)
{
    string temp = to_string(x);
    string tmp = to_string(n);
    int a = temp.find(tmp);
    if (a != -1)
        return true;
    else
        return false;
}

bool is_multiples_of_n(int x, int n)
{
    if (x % n == 0)
        return true;
    else
        return false;
}

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        if(is_have_n(i, n) || is_multiples_of_n(i, n))
        cout << i << ' ';
    }
    return 0;
}