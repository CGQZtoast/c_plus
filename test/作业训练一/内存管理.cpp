#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct memory //内存块
{
    int mark;    //标识符
    int length;  //所占长度
    bool usable; //true(1)可用，false(0)不可用
    memory(int mark_t, int len, bool usea)
    {
        this->mark = mark_t;
        this->length = len;
        this->usable = usea;
    }
};

bool cmp(const memory &a, const memory &b)
{
    if (a.usable == b.usable)
    {
        return a.mark < b.mark;
    }
    return a.usable < b.usable; //（已被占用）不可用false（0）<（未被占用）可用true（1）
}

int main()
{
    int t, m;
    cin >> t >> m;

    vector<memory> mms;
    vector<memory>::iterator it;

    int usable_size = m;
    int mark = 1;

    string operate;
    for (int i = 0; i < t; i++)
    {
        cin >> operate;
        if (operate == "alloc")
        {
            int n;
            cin >> n;
            bool flag = false;
            if (usable_size < n)
                cout << "NULL" << endl;
            else
            {
                for (it = mms.begin(); it != mms.end(); it++)
                {
                    if (it->usable == true && it->length >= n)
                    {
                        cout << mark << endl;
                        int temp = it->length;
                        it->mark = mark;
                        it->usable = false;
                        it->length = n;
                        mms.insert(it + 1, memory(-1, temp - n, true));
                        usable_size -= n;
                        mark++;
                        flag = true;
                        break;
                    }
                }
                if (flag == false)
                {
                    int sum = 0;
                    for (it = mms.begin(); it != mms.end(); it++)
                        sum += it->length;
                    if ((m - sum) >= n)
                    {
                        cout << mark << endl;
                        mms.push_back(memory(mark, n, false));
                        usable_size -= n;
                        mark++;
                    }
                    else
                        cout << "NULL" << endl;
                }
            }
        }
        else if (operate == "erase")
        {
            int x;
            cin >> x;
            bool flag = false;
            for (it = mms.begin(); it != mms.end(); it++)
            {
                if (it->mark == x)
                {
                    it->usable = true; //it标为空闲
                    it->mark = -1;     //删去it的标识符
                    usable_size += it->length;
                    flag = true;
                }
            }
            if (flag == false) //若命令无效
            {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        }
        else
        {
            sort(mms.begin(), mms.end(), cmp);
            for (unsigned j = 0; j < mms.size(); j++)
            {
                if (mms[j].usable == true)
                {
                    it = mms.begin() + j;
                    mms.erase(it);
                }
            }
        }
    }
}
