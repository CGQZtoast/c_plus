#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct result
{
    string str;
    int num;
};

bool cmp(result a, result b)
{
    return a.num < b.num;
}

int main()
{
    string words[1000];
    map<string, int> word_num;
    int num = 0;
    while (cin >> words[num] && words[num] != "#")
    {
        word_num[words[num]] = num + 1;
        num++;
    }

    string str;
    while (cin >> str && str != "#")
    {
        if (word_num[str]) // 字典中存在
            cout << str << " is correct" << endl;
        else // 字典中不存在
        {
            vector<result> ans;
            int len = str.length();
            // 删
            for (int i = 0; i < len; i++)
            {
                string temp = str;
                result tmp;
                temp.erase(temp.begin() + i);
                if (word_num[temp])
                {
                    tmp.str = temp;
                    tmp.num = word_num[temp];
                    ans.push_back(tmp);
                }
            }
            // 换
            for (int i = 0; i < len; i++)
                for (int j = 0; j < 26; j++)
                {
                    string temp = str;
                    result tmp;
                    temp[i] = 'a' + j;
                    if (word_num[temp])
                    {
                        tmp.str = temp;
                        tmp.num = word_num[temp];
                        ans.push_back(tmp);
                    }
                }
            // 插入
            for (int i = 0; i <= len; i++)
                for (int j = 0; j < 26; j++)
                {
                    string temp = str;
                    result tmp;
                    temp.insert(i, 1, 'a' + j);
                    if (word_num[temp])
                    {
                        tmp.str = temp;
                        tmp.num = word_num[temp];
                        ans.push_back(tmp);
                    }
                }

            sort(ans.begin(), ans.end(), cmp);
            cout << str << ": ";
            int size = ans.size();
            for (int i = 0; i < size; i++)
                cout << ans[i].str << ' ';
            cout << endl;
        }
    }
}