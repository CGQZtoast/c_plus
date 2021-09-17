#include <iostream>
using namespace std;

int N, n, key, sum[5000], ans[101], minn;

int look(int s) //寻找第一个前缀为s且后缀不为key的sum[i]的i
{
    int low = 1, high = n, mid;
    while (low < high - 1)
    {
        mid = (low + high) / 2;
        if (sum[mid] / 1000 >= s)
            high = mid;
        else
            low = mid;
    }
    if (sum[low] / 1000 != s)
        low = high;
    if (sum[low] / 1000 != s)
        return 0;
    while (sum[low] % 1000 == key && low < n && sum[low + 1] / 1000 == sum[low] / 1000)
        low++;
    if (sum[low] % 1000 == key)
        return 0;
    return low;
}

bool add(int d) //新增ans[d]，更新sum
{
    for (int i = 1; i < d; i++)
    {
        int k = look(ans[i] + ans[d]);
        if (k == 0)
            return false;
        sum[k] = sum[k] / 1000 * 1000 + key;
    }
    return true;
}

bool solve(int d)
{
    if (d > N)
    {
        for (int i = 1; i <= N; i++)
            cout << ans[i] << ((i < N) ? " " : "\n");
        return true;
    }
    while (sum[minn] % 1000 == key)
        minn++;
    ans[d] = sum[minn] / 1000 - ans[1];
    if (!add(d))
        return false;
    return solve(d + 1);
}

int main()
{
    while (cin >> N)
    {
        if (N == 0)
            break;
        n = N * (N - 1) / 2;
        sum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> sum[i];
            sum[i] *= 1000;
        }
        for (key = 3; key <= N; key++)
        {
            if ((sum[1] + sum[2] - sum[key]) / 1000 % 2)
                continue;
            ans[1] = (sum[1] + sum[2] - sum[key]) / 2000;
            bool flag = true;
            for (int i = 2; i <= key && flag; i++)
            {
                ans[i] = sum[i - 1] / 1000 - ans[1];
                if (!add(i))
                    flag = false;
            }
            if (!flag)
                continue;
            minn = 1;
            if (solve(key + 1))
                break;
        }
    }
    return 0;
}

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     while (cin >> n && n != 0)
//     {
//         int size = n * (n - 1) / 2;
//         int sum[size];
//         for (int i = 0; i < size; i++)
//             cin >> sum[i];

//         int ans[n];

//         for (int i = 2; i < size; i++)
//         {
//             ans[0] = (sum[0] + sum[1] - sum[i]) / 2;
//             ans[1] = sum[0] - ans[0];
//             ans[2] = sum[1] - ans[0];
//             if (ans[1] + ans[2] == sum[i])
//             {
//                 sum[0] = 0;
//                 sum[1] = 0;
//                 sum[i] = 0;
//                 break;
//             }
//         }

//         int k = 2;
//         for (int i = 3; i < n; i++)
//         {
//             while (sum[k] == 0)
//                 k++;

//             ans[i] = sum[k] - ans[0];
//             sum[k] = 0;

//             for (int j = 1; j < i; j++)
//             {
//                 for (int t = k + 1; t < size; t++)
//                 {
//                     if (sum[t] == ans[i] + ans[j])
//                     {
//                         sum[t] = 0;
//                         break;
//                     }
//                 }
//             }
//         }

//         for (int i = 0; i < n - 1; i++)
//             cout << ans[i] << ' ';
//         cout << ans[n - 1] << endl;
//     }

//     return 0;
// }