#include <iostream>
#include <set>
using namespace std;

struct block {
    int id, L, R;  // 经典左闭合
    block* next = NULL;

    block(int id_, int L_, int R_) {
        id = id_, L = L_, R = R_;
    }
};

int main() {
    int n, _, T;
    cin >> n >> _ >> T;

    block* head = new block(0, -1, 0);
    set<int> record;
    while (T--) {
        string opt; int id;
        cin >> opt >> id;
        if (opt == "in") {
            int arg; cin >> arg;
            if (record.find(id) != record.end()) {  // 判断是否已经占过座位
                cout << "no" << endl;
                continue;
            }
            record.insert(id);  // 打上标记
            bool flag = false;  // 标记是否分配成功
            for (block* ptr = head; ptr; ptr = ptr->next) {  // 从表头向后查找，每次检查是否能在当前位置之后分配座位
                if (ptr -> next) {  // 在 “中间” 插入块
                    if (ptr->next->L - ptr->R >= arg) {  // 如果空间足够则新建一个块
                        block* tmp = new block(id, ptr->R, ptr->R + arg);
                        tmp -> next = ptr -> next;
                        ptr -> next = tmp;

                        cout << "yes" << endl;
                        flag = true;
                        break;
                    }
                } else {  // 在最后追加块
                    if (ptr->R + arg <= n*n) {  // 否则尝试在最后添加块
                        block* tmp = new block(id, ptr->R, ptr->R + arg);
                        ptr -> next = tmp;

                        cout << "yes" << endl;
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) {
                record.erase(id);  // 一个也不要了
                cout << "no" << endl;
            }
        } else if (opt == "out") {  // 删除块
            bool flag = false;  // 标记是否找到目标块
            for (block* ptr = head; ptr->next; ptr = ptr->next) {
                if (ptr->next->id == id) {
                    block* tmp = ptr->next;
                    ptr -> next = ptr -> next -> next;
                    delete tmp;
                    flag = true;
                    record.erase(id);  // 删除标记
                    break;
                }
            }
            if (flag) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}