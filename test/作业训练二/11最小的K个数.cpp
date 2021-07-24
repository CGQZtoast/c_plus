#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    set<int> arr;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.insert(temp);
    }
    
    set<int>::iterator it;
    int temp = 0;
    for(it = arr.begin(); temp < k && it != arr.end(); it++, temp++)
        cout << *it << ' ';
}