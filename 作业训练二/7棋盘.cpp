#include <iostream>
using namespace std;

bool arr[2001][2001];
int N, num[2001], count = 0;

void dfs(int m, int n, int wide)
{
    if (arr[m][n] == 0)
        return ;
    if (m + wide > N || n + wide > N)
        return ;
    for (int i = m; i < m + wide; i++)
        for (int j = n; j < n + wide; j++)
        {
            if ((i + j - m - n) % 2 == 0 && arr[i][j] == 0)
                return ;
            else if ((i + j - m - n) % 2 == 1 && arr[i][j] == 1)
                return ;
        }
    
    if (wide > count)
        count = wide;
    num[wide]++;
    wide++;
    dfs(m, n, wide);
}

int main()
{
    cin >> N;
    getchar();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            arr[i][j] = getchar() - '0';
        getchar();
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dfs(i, j, 1);
    
    cout << count << ' ' << num[count] << endl;
}