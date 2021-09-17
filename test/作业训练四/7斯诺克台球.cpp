#include <iostream>
#include <map>
using namespace std;
struct people
{
    int n;
    int a[102];
    int sum;
    int dangan[102];
    int sss;
};
map<char, int> aa;
map<char, int> bb;
map<char, int> dd;
char cc[7] = {'r', 'y', 'g', 'c', 'b', 'p', 'B'};
int main()
{
    aa['r'] = 1;
    aa['y'] = 2;
    aa['g'] = 3;
    aa['c'] = 4;
    aa['b'] = 5;
    aa['p'] = 6;
    aa['B'] = 7;
    int t;
    cin >> t;
    getchar();
    people A, B;
    A.n = t;
    B.n = t;
    string x, y, X;
    int m = 0, k = 0, p = 0, hong = 15, huang = 1, lve = 1, cafe = 1, lan = 1, fen = 1, hei = 1;

    for (p = 0; p < t; p++)
    {
        hong = 15;
        huang = 1;
        lve = 1;
        cafe = 1;
        lan = 1;
        fen = 1;
        hei = 1;
        m = 0; //m表示第几个人
        A.a[p] = 0;
        A.sum = 0;
        A.dangan[p] = 0;
        A.sss = 0;
        B.a[p] = 0;
        B.sum = 0;
        B.dangan[p] = 0;
        B.sss = 0;
        x = "";
        y = "";
        k = 0; //k表示第几轮
        while (getline(cin, X) && X != "-1")
        {
            x = "";
            y = "";
            if (X.find(" ") != string::npos)
            {
                x = x + X.substr(0, X.find(" "));
                y = y + X.substr(X.find(" ") + 1);
            }
            else
            {
                x = x + X;
                y = "";
            }

            dd.clear();
            dd['r'] = 0;
            dd['y'] = 0;
            dd['g'] = 0;
            dd['c'] = 0;
            dd['b'] = 0;
            dd['p'] = 0;
            dd['B'] = 0;
            for (int i = 0; i < (int)x.length(); i++)
            {
                dd[x[i]]++;
            }
            int l = 0;
            for (int i = 0; i < 7; i++)
            {
                if (dd[cc[i]] != 0)
                    l++;
            }

            bb.clear();
            bb['r'] = 0;
            bb['y'] = 0;
            bb['g'] = 0;
            bb['c'] = 0;
            bb['b'] = 0;
            bb['p'] = 0;
            bb['B'] = 0;
            for (int i = 0; i < (int)y.length(); i++)
            {
                if (y[i] > '9' && y[i] != 'r')
                {
                    bb[y[i]]++;
                }
                else if (y[i] == 'r' && (y[i + 2] > '9' || i + 2 == (int)y.length()) && (y[i + 1] >= '1' && y[i + 1] <= '9'))
                {
                    bb[y[i]] = bb[y[i]] + (y[i + 1] - '0');
                    i++;
                }
                else if (y[i] == 'r' && (y[i + 2] >= '0' && y[i + 2] <= '9') && (y[i + 1] >= '1' && y[i + 1] <= '9'))
                {
                    bb[y[i]] = bb[y[i]] + (y[i + 1] - '0') * 10 + (y[i + 2] - '0');
                    i = i + 2;
                }
            }
            int q = 0;
            for (int i = 0; i < 7; i++)
            {
                if (bb[cc[i]] != 0)
                    q++;
            }

            if (x == "NULL") //x为空
            {
                k = 0;
                if (m % 2 == 0)
                {
                    B.a[p] = B.a[p] + 4;
                    m++;
                }
                else
                {
                    A.a[p] = A.a[p] + 4;
                    m++;
                }
            }
            else
            {
                if (hong > 0 && k % 2 == 0 && l == 1 && x[0] == 'r' && q == 1 && y[0] == 'r') //第一轮不犯规
                {
                    k = 1;
                    if (m % 2 == 0)
                    {
                        A.a[p] += bb['r'];
                        A.sum += bb['r'];
                    }
                    else
                    {
                        B.a[p] += bb['r'];
                        B.sum += bb['r'];
                    }
                }
                else if (hong >= 0 && k % 2 != 0 && (int)x.length() == 1 && x[0] != 'r' && q == 1 && y[0] == x[0]) //第二轮不犯规
                {
                    k = 0;
                    if (m % 2 == 0)
                    {
                        A.a[p] += aa[y[0]];
                        A.sum += aa[y[0]];
                    }
                    else
                    {
                        B.a[p] += aa[y[0]];
                        B.sum += aa[y[0]];
                    }
                }
                else if (k % 2 == 0 && x[0] == 'r' && hong > 0 && l == 1 && (int)y.length() == 0) //y为空
                {
                    if (m % 2 == 0)
                    {
                        if (A.sum >= 100)
                            A.dangan[p]++;
                        A.sum = 0;
                    }
                    else
                    {
                        if (B.sum >= 100)
                            B.dangan[p]++;
                        B.sum = 0;
                    }
                    m++;
                    k = 0;
                }
                else if (k % 2 != 0 && x[0] != 'r' && hong >= 0 && l == 1 && q == 0) //y为空
                {
                    if (m % 2 == 0)
                    {
                        if (A.sum >= 100)
                            A.dangan[p]++;
                        A.sum = 0;
                    }
                    else
                    {
                        if (B.sum >= 100)
                            B.dangan[p]++;
                        B.sum = 0;
                    }
                    m++;
                    k = 0;
                }
                else if (k % 2 == 0 && hong <= 0)
                {
                    if (huang == 1)
                    {
                        if ((int)x.length() == 1 && (int)y.length() == 1 && x[0] == 'y' && y[0] == 'y')
                        {
                            if (m % 2 == 0)
                            {
                                A.a[p] += aa[y[0]];
                                A.sum += aa[y[0]];
                            }
                            else
                            {
                                B.a[p] += aa[y[0]];
                                B.sum += aa[y[0]];
                            }
                            huang = 0;
                        }
                        else if ((int)x.length() == 1 && (int)y.length() == 0 && x[0] == 'y')
                        {
                            if (m % 2 == 0)
                            {
                                if (A.sum >= 100)
                                    A.dangan[p]++;
                                A.sum = 0;
                            }
                            else
                            {
                                if (B.sum >= 100)
                                    B.dangan[p]++;
                                B.sum = 0;
                            }
                            m++;
                        }
                        else
                        {
                            k = 0;
                            if (m % 2 == 0)
                            {
                                //if(bb['r']>7) B.a[p]+=bb['r'];
                                if (bb['B'] == 1 || dd['B'] == 1)
                                    B.a[p] += 7;
                                else if (bb['p'] == 1 || dd['p'] == 1)
                                    B.a[p] += 6;
                                else if (bb['b'] == 1 || dd['b'] == 1)
                                    B.a[p] += 5;
                                else
                                    B.a[p] += 4;
                                m++;
                                if (A.sum >= 100)
                                    A.dangan[p]++;
                                A.sum = 0;
                            }
                            else
                            {
                                //if(bb['r']>7) A.a[p]+=bb['r'];
                                if (bb['B'] == 1 || dd['B'] == 1)
                                    A.a[p] += 7;
                                else if (bb['p'] == 1 || dd['p'] == 1)
                                    A.a[p] += 6;
                                else if (bb['b'] == 1 || dd['b'] == 1)
                                    A.a[p] += 5;
                                else
                                    A.a[p] += 4;
                                m++;
                                if (B.sum >= 100)
                                    B.dangan[p]++;
                                B.sum = 0;
                            }
                        }
                    }

                    else if (huang == 0 && lve == 1)
                    {
                        if (x.length() == 1 && y.length() == 1 && x[0] == 'g' && y[0] == 'g')
                        {
                            if (m % 2 == 0)
                            {
                                A.a[p] += aa[y[0]];
                                A.sum += aa[y[0]];
                            }
                            else
                            {
                                B.a[p] += aa[y[0]];
                                B.sum += aa[y[0]];
                            }
                            lve = 0;
                        }
                        else if (x.length() == 1 && y.length() == 0 && x[0] == 'g')
                        {
                            if (m % 2 == 0)
                            {
                                if (A.sum >= 100)
                                    A.dangan[p]++;
                                A.sum = 0;
                            }
                            else
                            {
                                if (B.sum >= 100)
                                    B.dangan[p]++;
                                B.sum = 0;
                            }
                            m++;
                        }
                        else
                        {
                            if (m % 2 == 0)
                            {
                                //if(bb['r']>7) B.a[p]+=bb['r'];
                                if (bb['B'] == 1 || dd['B'] == 1)
                                    B.a[p] += 7;
                                else if (bb['p'] == 1 || dd['p'] == 1)
                                    B.a[p] += 6;
                                else if (bb['b'] == 1 || dd['b'] == 1)
                                    B.a[p] += 5;
                                else
                                    B.a[p] += 4;
                                m++;
                                if (A.sum >= 100)
                                    A.dangan[p]++;
                                A.sum = 0;
                            }
                            else
                            {
                                //if(bb['r']>7) A.a[p]+=bb['r'];
                                if (bb['B'] == 1 || dd['B'] == 1)
                                    A.a[p] += 7;
                                else if (bb['p'] == 1 || dd['p'] == 1)
                                    A.a[p] += 6;
                                else if (bb['b'] == 1 || dd['b'] == 1)
                                    A.a[p] += 5;
                                else
                                    A.a[p] += 4;
                                m++;
                                if (B.sum >= 100)
                                    B.dangan[p]++;
                                B.sum = 0;
                            }
                        }
                    }

                    else if (huang == 0 && lve == 0 && cafe == 1)
                    {
                        if (x.length() == 1 && y.length() == 1 && x[0] == 'c' && y[0] == 'c')
                        {
                            if (m % 2 == 0)
                            {
                                A.a[p] += aa[y[0]];
                                A.sum += aa[y[0]];
                            }
                            else
                            {
                                B.a[p] += aa[y[0]];
                                B.sum += aa[y[0]];
                            }
                            cafe = 0;
                        }
                        else if (x.length() == 1 && y.length() == 0 && x[0] == 'c')
                        {
                            if (m % 2 == 0)
                            {
                                if (A.sum >= 100)
                                    A.dangan[p]++;
                                A.sum = 0;
                            }
                            else
                            {
                                if (B.sum >= 100)
                                    B.dangan[p]++;
                                B.sum = 0;
                            }
                            m++;
                        }
                        else
                        {
                            if (m % 2 == 0)
                            {
                                //if(bb['r']>7) B.a[p]+=bb['r'];
                                if (bb['B'] == 1 || dd['B'] == 1)
                                    B.a[p] += 7;
                                else if (bb['p'] == 1 || dd['p'] == 1)
                                    B.a[p] += 6;
                                else if (bb['b'] == 1 || dd['b'] == 1)
                                    B.a[p] += 5;
                                else
                                    B.a[p] += 4;
                                m++;
                                if (A.sum >= 100)
                                    A.dangan[p]++;
                                A.sum = 0;
                            }
                            else
                            {
                                //if(bb['r']>7) A.a[p]+=bb['r'];
                                if (bb['B'] == 1 || dd['B'] == 1)
                                    A.a[p] += 7;
                                else if (bb['p'] == 1 || dd['p'] == 1)
                                    A.a[p] += 6;
                                else if (bb['b'] == 1 || dd['b'] == 1)
                                    A.a[p] += 5;
                                else
                                    A.a[p] += 4;
                                m++;
                                if (B.sum >= 100)
                                    B.dangan[p]++;
                                B.sum = 0;
                            }
                        }
                    }

                    else if (lan == 1 && cafe == 0 && huang == 0 && lve == 0)
                    {
                        if (x.length() == 1 && y.length() == 1 && x[0] == 'b' && y[0] == 'b')
                        {
                            if (m % 2 == 0)
                            {
                                A.a[p] += aa[y[0]];
                                A.sum += aa[y[0]];
                            }
                            else
                            {
                                B.a[p] += aa[y[0]];
                                B.sum += aa[y[0]];
                            }
                            lan = 0;
                        }
                        else if (x.length() == 1 && y.length() == 0 && x[0] == 'b')
                        {
                            if (m % 2 == 0)
                            {
                                if (A.sum >= 100)
                                    A.dangan[p]++;
                                A.sum = 0;
                            }
                            else
                            {
                                if (B.sum >= 100)
                                    B.dangan[p]++;
                                B.sum = 0;
                            }
                            m++;
                        }
                        else
                        {
                            k = 0;
                            if (m % 2 == 0)
                            {
                                //if(bb['r']>7) B.a[p]+=bb['r'];
                                if (bb['B'] == 1 || dd['B'] == 1)
                                    B.a[p] += 7;
                                else if (bb['p'] == 1 || dd['p'] == 1)
                                    B.a[p] += 6;
                                else if (bb['b'] == 1 || dd['b'] == 1)
                                    B.a[p] += 5;
                                else
                                    B.a[p] += 4;
                                m++;
                                if (A.sum >= 100)
                                    A.dangan[p]++;
                                A.sum = 0;
                            }
                            else
                            {
                                //if(bb['r']>7) A.a[p]+=bb['r'];
                                if (bb['B'] == 1 || dd['B'] == 1)
                                    A.a[p] += 7;
                                else if (bb['p'] == 1 || dd['p'] == 1)
                                    A.a[p] += 6;
                                else if (bb['b'] == 1 || dd['b'] == 1)
                                    A.a[p] += 5;
                                else
                                    A.a[p] += 4;
                                m++;
                                if (B.sum >= 100)
                                    B.dangan[p]++;
                                B.sum = 0;
                            }
                        }
                    }

                    else if (fen == 1 && lan == 0 && cafe == 0 && huang == 0 && lve == 0)
                    {
                        if (x.length() == 1 && y.length() == 1 && x[0] == 'p' && y[0] == 'p')
                        {
                            if (m % 2 == 0)
                            {
                                A.a[p] += aa[y[0]];
                                A.sum += aa[y[0]];
                            }
                            else
                            {
                                B.a[p] += aa[y[0]];
                                B.sum += aa[y[0]];
                            }
                            fen = 0;
                        }
                        else if (x.length() == 1 && y.length() == 0 && x[0] == 'p')
                        {
                            if (m % 2 == 0)
                            {
                                if (A.sum >= 100)
                                    A.dangan[p]++;
                                A.sum = 0;
                            }
                            else
                            {
                                if (B.sum >= 100)
                                    B.dangan[p]++;
                                B.sum = 0;
                            }
                            m++;
                        }
                        else
                        {
                            if (m % 2 == 0)
                            {
                                //if(bb['r']>7) B.a[p]+=bb['r'];
                                if (bb['B'] == 1 || dd['B'] == 1)
                                    B.a[p] += 7;
                                else if (bb['p'] == 1 || dd['p'] == 1)
                                    B.a[p] += 6;
                                else if (bb['b'] == 1 || dd['b'] == 1)
                                    B.a[p] += 5;
                                else
                                    B.a[p] += 4;
                                m++;
                                if (A.sum >= 100)
                                    A.dangan[p]++;
                                A.sum = 0;
                            }
                            else
                            {
                                //if(bb['r']>7) A.a[p]+=bb['r'];
                                if (bb['B'] == 1 || dd['B'] == 1)
                                    A.a[p] += 7;
                                else if (bb['p'] == 1 || dd['p'] == 1)
                                    A.a[p] += 6;
                                else if (bb['b'] == 1 || dd['b'] == 1)
                                    A.a[p] += 5;
                                else
                                    A.a[p] += 4;
                                m++;
                                if (B.sum >= 100)
                                    B.dangan[p]++;
                                B.sum = 0;
                            }
                        }
                    }

                    else if (hei == 1 && fen == 0 && lan == 0 && cafe == 0 && huang == 0 && lve == 0)
                    {
                        if (x.length() == 1 && y.length() == 1 && x[0] == 'B' && y[0] == 'B')
                        {
                            if (m % 2 == 0)
                            {
                                A.a[p] += aa[y[0]];
                                A.sum += aa[y[0]];
                            }
                            else
                            {
                                B.a[p] += aa[y[0]];
                                B.sum += aa[y[0]];
                            }
                            hei = 0;
                        }
                        else if (x.length() == 1 && y.length() == 0 && x[0] == 'B')
                        {
                            if (m % 2 == 0)
                            {
                                if (A.sum >= 100)
                                    A.dangan[p]++;
                                A.sum = 0;
                            }
                            else
                            {
                                if (B.sum >= 100)
                                    B.dangan[p]++;
                                B.sum = 0;
                            }
                            m++;
                        }
                        else
                        {
                            if (m % 2 == 0)
                            {
                                //if(bb['r']>7) B.a[p]+=bb['r'];
                                if (bb['B'] == 1 || dd['B'] == 1)
                                    B.a[p] += 7;
                                else if (bb['p'] == 1 || dd['p'] == 1)
                                    B.a[p] += 6;
                                else if (bb['b'] == 1 || dd['b'] == 1)
                                    B.a[p] += 5;
                                else
                                    B.a[p] += 4;
                                m++;
                                if (A.sum >= 100)
                                    A.dangan[p]++;
                                A.sum = 0;
                            }
                            else
                            {
                                //if(bb['r']>7) A.a[p]+=bb['r'];
                                if (bb['B'] == 1 || dd['B'] == 1)
                                    A.a[p] += 7;
                                else if (bb['p'] == 1 || dd['p'] == 1)
                                    A.a[p] += 6;
                                else if (bb['b'] == 1 || dd['b'] == 1)
                                    A.a[p] += 5;
                                else
                                    A.a[p] += 4;
                                m++;
                                if (B.sum >= 100)
                                    B.dangan[p]++;
                                B.sum = 0;
                            }
                        }
                    }
                }
                else //犯规
                {
                    k = 0;
                    if (m % 2 == 0)
                    {
                        //if(bb['r']>7) B.a[p]+=bb['r'];
                        if (bb['B'] == 1 || dd['B'] == 1)
                            B.a[p] += 7;
                        else if (bb['p'] == 1 || dd['p'] == 1)
                            B.a[p] += 6;
                        else if (bb['b'] == 1 || dd['b'] == 1)
                            B.a[p] += 5;
                        else
                            B.a[p] += 4;
                        m++;
                        if (A.sum >= 100)
                            A.dangan[p]++;
                        A.sum = 0;
                    }
                    else
                    {
                        //if(bb['r']>7) A.a[p]+=bb['r'];
                        if (bb['B'] == 1 || dd['B'] == 1)
                            A.a[p] += 7;
                        else if (bb['p'] == 1 || dd['p'] == 1)
                            A.a[p] += 6;
                        else if (bb['b'] == 1 || dd['b'] == 1)
                            A.a[p] += 5;
                        else
                            A.a[p] += 4;
                        m++;
                        if (B.sum >= 100)
                            B.dangan[p]++;
                        B.sum = 0;
                    }
                }
            }
            hong = hong - bb['r'];
        }
        cout << A.a[p] << ":" << B.a[p] << endl;
        if (A.sum >= 100)
            A.dangan[p]++;
        if (B.sum >= 100)
            B.dangan[p]++;
    }
    for (int i = 0; i < t; i++)
    {
        if (A.dangan[i] != 0)
            A.sss++;
        if (B.dangan[i] != 0)
            B.sss++;
    }
    cout << A.sss << ":" << B.sss;
    return 0;
}
