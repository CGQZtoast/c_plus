#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100002;

struct Edge {
    int dst, val;
};

int n;
vector<vector<Edge>> head(maxn);
vector<int> arr(maxn);  // 顶点上的数字
vector<bool> flag(maxn);  // 标记该节点是否有瑕疵

void find_all_bad(int now, int par, int sum) {  // 找出所有有瑕疵的节点
    flag[now] = sum > arr[now];
    for (Edge nxt : head[now]) {
        if (nxt.dst == par) continue;
        find_all_bad(nxt.dst, now, max(sum + nxt.val, nxt.val));  // 参考「最大子段和」算法
    }
}

int count_not_bad(int now, int par) {  // 统计剩余没有瑕疵的节点
    if (flag[now]) return 0;
    int sum = 0;
    for (Edge nxt : head[now]) {
        if (nxt.dst == par) continue;
        sum += count_not_bad(nxt.dst, now);
    }
    return sum + 1;  // 最后加上自己
}

int main() {  //: T5-10
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        int src = i + 1, dst, val;
        cin >> dst >> val;
        head[src].push_back({dst, val});
        head[dst].push_back({src, val});
    }
    find_all_bad(1, 0, 0);
    cout << (n - count_not_bad(1, 0)) << endl;
    return 0;
}