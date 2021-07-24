#include <iostream>
#include <algorithm>
using namespace std;

struct title
{
    string name;
    string name_;
    int count;
};

bool cmp(title a, title b)
{
    return a.count > b.count;
}

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        getchar();
        title titles[n];
        for (int i = 0; i < n; i++)
        {
            getline(cin, titles[i].name, '\n');
            cin >> titles[i].count;
            getchar();
            // 保存全是小写的情况
            int len = titles[i].name.length();
            for (int j = 0; j < len; j++)
            {
                if (titles[i].name[j] >= 'A' && titles[i].name[j] <= 'Z')
                    titles[i].name_ += (titles[i].name[j] - 'A' + 'a');
                else
                    titles[i].name_ += titles[i].name[j];
            }
        }

        int m;
        cin >> m;
        getchar();
        string test;
        for (int i = 0; i < m; i++)
        {
            title ans[n];
            int k = 0;
            getline(cin, test, '\n');
            for (int j = 0; j < n; j++)
            {
                // 搜索的字符串是连续的情况
                int cur1 = titles[j].name.find(test);
                int cur2 = titles[j].name_.find(test);
                int size = test.length();
                int len = titles[j].name.length();
                if (cur1 != -1 && (cur1 + size == len || titles[j].name[cur1 + size] == ' ') && (cur1 == 0 || titles[j].name[cur1 - 1] == ' '))
                {
                    ans[k] = titles[j];
                    k++;
                }
                else if (cur2 != -1 && (cur2 + size == len || titles[j].name[cur2 + size] == ' ') && (cur2 == 0 || titles[j].name[cur2 - 1] == ' '))
                {
                    ans[k] = titles[j];
                    k++;
                }
            }
            sort(ans, ans + k, cmp);
            for (int j = 0; j < k; j++)
                cout << ans[j].name << endl;
            cout << "***" << endl;
        }
        cout << "---" << endl;
    }
    return 0;
}