#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string standard_tel(string tel)
{
    int n = tel.length();
    string new_tel;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (tel[i] >= '0' && tel[i] <= '9')
            new_tel += tel[i];
        else if (tel[i] == 'A' || tel[i] == 'B' || tel[i] == 'C')
            new_tel += '2';
        else if (tel[i] == 'D' || tel[i] == 'E' || tel[i] == 'F')
            new_tel += '3';
        else if (tel[i] == 'G' || tel[i] == 'H' || tel[i] == 'I')
            new_tel += '4';
        else if (tel[i] == 'J' || tel[i] == 'K' || tel[i] == 'L')
            new_tel += '5';
        else if (tel[i] == 'M' || tel[i] == 'N' || tel[i] == 'O')
            new_tel += '6';
        else if (tel[i] == 'P' || tel[i] == 'R' || tel[i] == 'S')
            new_tel += '7';
        else if (tel[i] == 'T' || tel[i] == 'U' || tel[i] == 'V')
            new_tel += '8';
        else if (tel[i] == 'W' || tel[i] == 'X' || tel[i] == 'Y')
            new_tel += '9';
        if (tel[i] != '-')
            flag++;
        if (flag == 3)
        {
            new_tel += '-';
            flag++;
        }
    }
    return new_tel;
}

int main()
{
    int n;
    cin >> n;
    string str[n];
    
    map<string, int> tel_count;

    string id[n];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        if(!tel_count[standard_tel(str[i])])
        {
            tel_count[standard_tel(str[i])] = 1;
            id[k] = standard_tel(str[i]);
            k++;
        }
        else
            tel_count[standard_tel(str[i])] += 1;
    }

    sort(id, id + k);

    for(int i = 0; i < k; i++)
        if(tel_count[id[i]] > 1)
            cout << id[i] << ' ' << tel_count[id[i]] << endl;

    return 0;
}