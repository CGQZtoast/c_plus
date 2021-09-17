#include <iostream>
using namespace std;
int main()
{
    int M1 = 0, M2 = 0, R1 = 0, R2 = 0, R3 = 0;
    string order;
    while (cin >> M1 >> M2 >> order)
    {
        for (unsigned int i = 0; i < order.length(); i++)
        {
            if (order[i] == 'A')
                R1 = M1;
            else if (order[i] == 'B')
                R2 = M2;
            else if (order[i] == 'C')
                M1 = R3;
            else if (order[i] == 'D')
                M2 = R3;
            else if (order[i] == 'E')
                R3 = R1 + R2;
            else
                R3 = R1 - R2;
        }
        cout << M1 << ',' << M2 << endl;
    }
}