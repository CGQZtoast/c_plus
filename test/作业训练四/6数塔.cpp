#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // int **tower = new int*[n];
    int tower[n][n];
    for (int i = 0; i < n; i++)
    {
        // tower[i] = new int[i];
        for (int j = 0; j <= i; j++)
            cin >> tower[i][j];
    }

    // int **max_temp = new int*[n];
    int max_temp[n][n];
    for (int i = n - 1; i >= 0; i--) // 第i行（从下往上判断）
    {
        // max_temp[i] = new int[i];
        if (i == n - 1) // 最后一行的最大值为本身
        {
            for (int j = 0; j < n; j++)
                max_temp[i][j] = tower[i][j];
            continue;
        }

        for (int j = 0; j <= i; j++)
            max_temp[i][j] = max(tower[i][j] + max_temp[i + 1][j], tower[i][j] + max_temp[i + 1][j + 1]);
    }

    cout << max_temp[0][0] << endl;
    
    int k = 0, t = 0;
    while (k < n - 1)
    {
        cout << tower[k][t] << ' ';
        if (max_temp[k][t] - max_temp[k + 1][t + 1] == tower[k][t]) 
            t++;
        k++;
    }
    cout << tower[k][t] << ' ';

    return 0;
}