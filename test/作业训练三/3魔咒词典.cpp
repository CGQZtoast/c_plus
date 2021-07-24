#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<string, string> a_to_b;
    map<string, string> b_to_a;    

    string str, str1, str2;
    while (getline(cin, str, '\n') && str != "@END@")
    {
        int pos1 = str.find('[');
        int pos2 = str.find(']');
        str1 = str.substr(pos1 + 1, pos2 - pos1 - 1);
        str2 = str.substr(pos2 + 2);
        a_to_b[str1] = str2;
        b_to_a[str2] = str1;

        // cout << str1 << "---" << str2 << endl;
    }

    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, str, '\n');
        int cur = str.find('[');
        if (cur != -1)
            str = str.substr(1, str.length() - 2);
        if (a_to_b[str] != "")
            cout << a_to_b[str] << endl;
        else if (b_to_a[str] != "")
            cout << b_to_a[str] << endl; 
        else 
            cout << "what?" << endl;
    }
}