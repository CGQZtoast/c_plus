#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
struct people
{
    char id[19];   // 身份证号码
    int social;    // 社保缴纳月数
    int area;      // 现有住房面积
    char date[11]; // 申报日期
    // 重载 < 用于排序 (关键)
    bool operator<(const people &b) const
    {
        if (area == 0 && social <= 24)
            return 0;
        if (b.area == 0 && b.social <= 24)
            return 1;
        if (area != b.area)
            return area < b.area;
        if (area == 0 && social != b.social)
            return social > b.social;
        for (int i = 6; i < 10; ++i)
            if (date[i] != b.date[i])
                return date[i] < b.date[i];
        for (int i = 0; i < 2; ++i)
            if (date[i] != b.date[i])
                return date[i] < b.date[i];
        for (int i = 3; i < 5; ++i)
            if (date[i] != b.date[i])
                return date[i] < b.date[i];
        return 0;
    }
};

people *getMess(int &n);

int main()
{
    int m, T;
    cin >> m >> T;

    people *person; // 指向所有报名人的基本资料首地址,通过调用函数getMess获取
    int n;          // n为报名人数,通过调用函数getMess获取
    person = getMess(n);

    sort(person, person + n); // 将报名人的资料按要求排序

    map<string, int> rank;    // 省份证号与排名的键值对
    map<int, int> rank_count; // 排名与相同排名的人数的键值对

    rank[person[0].id] = 1;
    rank_count[rank[person[0].id]] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (person[i].area == 0 && person[i].social <= 24)
        {
            // 不满足刚性需求 排名为-1 相同排名人数为0(不用管)
            rank[person[i].id] = -1;
            rank_count[rank[person[i].id]] = 0;
        }
        if (person[i] < person[i + 1])
        {
            rank[person[i + 1].id] = i + 2;
            rank_count[rank[person[i + 1].id]] = 1;
        }
        else
        {
            rank[person[i + 1].id] = rank[person[i].id];
            rank_count[rank[person[i].id]]++;
        }
    }

    string id;
    for (int i = 0; i < T; i++)
    {
        cin >> id;
        //  1. 申请者不符合购房条件或排位超出了所推出的房源数量不能中签,则输出"Sorry"
        if (rank[id] > m || rank[id] < 0)
            cout << "Sorry" << endl;
        else
        {
            int num = rank_count[rank[id]];
            //  2. 申请者符合购房条件,且该名次人数为1人,则直接输出一个整数,表示选房顺序号
            if (num == 1)
                cout << rank[id] << endl;
            //  3. 申请者符合购房条件,且该名次人数有多人,同时人数不大于所剩房源数量,则直接输出用空格分隔的两个整数,表示选房顺序号区间
            else if (rank[id] + num - 1 <= m)
                cout << rank[id] << " " << rank[id] + num - 1 << endl;
            // 4. 申请者符合购房条件,且该名次人数有多人,同时人数大于所剩房源数量,则输出用/分隔两个整数,如 A/B,表示 B 人中选 A 人,选房顺序为排名倒数 A 名范围
            else
                cout << m - rank[id] + 1 << "/" << num << endl;
        }
    }
    return 0;
}

people *getMess(int &n) /* 将文件数据读入内存 */
{
    FILE *fp;
    fp = fopen("house.bin", "rb");
    fseek(fp, -1 * (long)sizeof(int), 2);
    fread(&n, sizeof(int), 1, fp);
    rewind(fp);
    people *tmp = new people[n];
    fread(tmp, sizeof(people), n, fp);
    fclose(fp);
    return tmp;
}