#include <iostream>
using namespace std;

int main()
{
    string str;
    while (cin >> str && str != "ENDOFINPUT")
    {
        string temp;
        while (cin >> temp && temp != "END")
        {
            for (unsigned int i = 0; i < temp.length(); i++)
            {
                if (temp[i] >= 'A' && temp[i] <= 'Z')
                    temp[i] = 'A' + (temp[i] - 'A' + 21) % 26;
                cout << temp[i];
            }
            cout << ' ';   
        }
        cout << endl;
    }
}