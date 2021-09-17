#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int id, flag;
    vector<int> child;
    bool operator< (const Node& other) const {
        return id > other.id;
    }
};

int n;
vector<Node> arr;

bool judge(int index) {
    if (!arr[index].flag) return false;
    for (int ptr : arr[index].child) {
        if (!arr[ptr].flag) {
            return false;
        }
    }
    return true;
}

int main() {  //: T5-3
    cin >> n;
    arr = vector<Node>(n+1);
    for (int i = 1; i <= n; i++) {  // 读入 & 建树
        int p, c; cin >> p >> c;
        arr[i].id = i, arr[i].flag = c;
        if (~p) arr[p].child.push_back(i);
    }

    priority_queue<Node> task;
    // 遍历整棵树判断节点是否可以删除
    for (int i = 1; i <= n; i++) {
        if (judge(i)) task.push(arr[i]);
    }

    if (task.empty()) {
        cout << "-1" << endl;
        return 0;
    }
    while (!task.empty()) {
        cout << task.top().id << " ";
        task.pop();
    }
    return 0;
}