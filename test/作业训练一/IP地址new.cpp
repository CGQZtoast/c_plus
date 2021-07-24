#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

string type10_to_2(string type10_num)
{
    int num = 0;
    stringstream ss;
    ss.str(type10_num);   
    ss >> num;
    ss.clear();

    string type2_num;
    while (num)
    {
        type2_num += to_string(num % 2);
        num /= 2;
    }
    return type2_num;
}

int count_1(string type2_num)
{
    int count = 0;
    int n = type2_num.length();
    for (int i = 0; i < n; i++)
        if (type2_num[i] == '1')
            count++;
    return count;
}

int main()
{
    int n;
    cin >> n;
    getchar();
    string IP1, IP2, IP3, IP4;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        getline(cin, IP1, '.');
        getline(cin, IP2, '.');
        getline(cin, IP3, '.');
        getline(cin, IP4, '\n');

        count = 0;
        count = count_1(type10_to_2(IP1)) + count_1(type10_to_2(IP2)) + count_1(type10_to_2(IP3)) + count_1(type10_to_2(IP4));
        cout << count << endl;
    }
}