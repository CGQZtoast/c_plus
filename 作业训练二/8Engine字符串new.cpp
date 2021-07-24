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
            int count = 0;
            getline(cin, test, '\n');

            // 分割字符串(并转化为小写)
            string str[10];
            int num = 0;
            int len = test.length();
            for (int k = 0; k < len; k++)
            {
                if (test[k] != ' ')
                    str[num] += test[k];
                else
                    num++;
            }
            num++;

            for (int j = 0; j < n; j++)
            {
                int temp = 0;
                for (int k = 0; k < num; k++)
                {
                    int cur = titles[j].name_.find(str[k]);
                    int size = str[k].length();
                    int len_ = titles[j].name_.length();
                    if (cur != -1 && (cur == 0 || titles[j].name_[cur - 1] == ' ') && (cur + size == len_ || titles[j].name_[cur + size] == ' '))
                        temp++;
                }
                if (temp == num)
                {
                    ans[count] = titles[j];
                    count++;
                }
            }

            sort(ans, ans + count, cmp);
            for (int j = 0; j < count; j++)
                cout << ans[j].name << endl;
            cout << "***" << endl;
        }
        cout << "---" << endl;
    }
    return 0;
}