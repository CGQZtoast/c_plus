#include <iostream>
using namespace std;
int main()
{
    int N, A, B, C;
    while (cin >> N >> A >> B >> C)
    {
        string mark[N];
        for (int i = 0; i < N; i++)
            cin >> mark[i];

        int num = (A * C + B) % 6 + 1;
        int Lele = 0, Yueyue = 0;
        int temp = 1;

        bool grid[N];
        for (int i = 0; i < N; i++)
            grid[i] = true;

        while (Lele != N - 1 && Yueyue != N - 1)
        {
            if (temp % 2 == 1)
            {
                grid[Lele] = true;
                Lele += num;
                
                while (Lele < 0 || Lele > N - 1)
                {
                    if (Lele < 0)
                        Lele *= -1;
                    if (Lele > N - 1)
                        Lele = N - 1 - (Lele - (N - 1));
                }
                    
                if (mark[Lele] != "N")
                    Lele = mark[Lele][1] - '0';
                if (Lele != 0 && grid[Lele] == false)
                    Lele = 0;
                grid[Lele] = false;
            }
            else
            {
                grid[Yueyue] = true;
                Yueyue += num;
                
                while (Yueyue < 0 || Yueyue > N - 1)
                {
                    if (Yueyue < 0)
                        Yueyue *= -1;
                    if (Yueyue > N - 1)
                        Yueyue = N - 1 - (Yueyue - (N - 1));
                }

                if (mark[Yueyue] != "N")
                    Yueyue = mark[Yueyue][1] - '0';
                if (Yueyue != 0 && grid[Yueyue] == false)
                    Yueyue = 0;
                grid[Yueyue] = false;
            }

            num = (A * num + B) % 6 + 1;
            temp++;

            if (Lele == N - 1)
                cout << "Lele" << endl;
            if (Yueyue == N - 1)
                cout << "Yueyue" << endl;
        }
    }
}