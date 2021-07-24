#include <iostream>
#include <algorithm>
using namespace std;

struct len
{
    int n;
    int len_;
};

bool cmp(len a, len b)
{
    if (a.len_ != b.len_)
        return a.len_ < b.len_;
    return a.n < b.n;
}

int main()
{
    int n;
    cin >> n;
    len arr[n];
    // int max = INT_MIN;
    // int min = INT_MAX;
    int max = -10000;
    int min = 10000;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].n;
        if (arr[i].n > max)
            max = arr[i].n;
        if (arr[i].n < min)
            min = arr[i].n;
    }

    for (int i = 0; i < n; i++)
        arr[i].len_ = abs(max + min - 2 * arr[i].n);

    sort(arr, arr + n, cmp);

    cout << arr[0].n << endl;
}
