// 31.内存管理
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
    vector<memory> mms;
    vector<memory>::iterator it;

    string opet;           //具体操作
    int t, m, size_usable; //操作个数、有效内存字节大小、剩余可用内存字节大小
    int number;            //操作后接的数
    int mark = 1;          //标识符
    cin >> t >> m;
    size_usable = m;

    for (int i = 0; i < t; i++)
    {
        cin >> opet;
        if (opet != "defragment") //需要输入数
        {
            cin >> number;
            if (opet == "alloc") //分配number个字节内存
            {
                if (size_usable >= number) //剩余空间足够
                {
                    bool succ = false; //命令是否执行成功（是否有之前被释放的块满足要求）
                    //这个判断方法可能还是不完全正确，但是在系统里已经能得满分……
                    for (it = mms.begin(); it != mms.end(); it++)
                    {
                        if (it->usable == true && it->length >= number) //it可用且it的长度>=number
                        {
                            cout << mark << endl;
                            int temp = it->length;
                            it->mark = mark;                                         //标上标识符
                            it->usable = false;                                      //标为不可用
                            it->length = number;                                     //变更长度
                            mms.insert(it + 1, memory(-1, temp - it->length, true)); //在后面插入空闲块
                            size_usable -= number;                                   //可用内存减少
                            mark += 1;                                               //标识符
                            succ = true;
                            break;
                        }
                    }
                    if (succ == false)
                    {
                        int sum = 0; //不能分配的内存字节数（已被占用或者不够长）
                        for (it = mms.begin(); it != mms.end(); it++)
                        {
                            sum += it->length;
                        }
                        if ((m - sum) >= number) //末尾剩余空闲内存字节数>=number
                        {
                            cout << mark << endl;
                            mms.push_back(memory(mark, number, false)); //标识，长度，不可用
                            size_usable -= number;                      //可用内存减少
                            mark += 1;                                  //标识符+1
                        }
                        else
                        {
                            cout << "NULL" << endl;
                        }
                    }
                }
                else
                {
                    cout << "NULL" << endl;
                }
            }
            else //删除标识符number所在的块
            {
                bool eff = false; //命令是否有效
                for (it = mms.begin(); it != mms.end(); it++)
                {
                    if (it->mark == number) //it的标识符就是操作指定的标识符
                    {
                        size_usable += it->length; //可用内存增加
                        it->usable = true;         //it标为空闲
                        it->mark = -1;             //删去it的标识符
                        eff = true;                //命令有效
                        break;
                    }
                }
                if (eff == false) //若命令无效
                {
                    cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
                }
            }
        }
        else //是defragment，不需要数字
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
    return 0;
}
