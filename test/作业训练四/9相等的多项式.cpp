#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;                      //多项式最高次数
    vector<int> ai;             //多项式a
    map<int, int> bi, aiExband; //多项式b、多项式a的展开
    //map<次数,对应项的系数>
    while (cin >> n && n != 0)
    {
        int temp;
        ai.clear(), bi.clear(), aiExband.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            ai.push_back(temp);
        }
        bi[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            cin >> temp;
            bi[i] = temp;
        }

        //多项式a的展开
        aiExband[0] = ai[0], aiExband[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (j != i && j != 0)
                {
                    aiExband[j] = aiExband[j] * ai[i - 1] + aiExband[j - 1];
                }
                else if (j == i) //当前最高次数项的系数一定是1
                {
                    aiExband[j] = 1;
                }
                else //j=0
                {
                    aiExband[j] *= ai[i - 1];
                }
            }
        }
        if (bi == aiExband)
        {
            cout << 'Y' << endl;
        }
        else
        {
            cout << 'N' << endl;
        }
    }
    return 0;
}
