#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100002;

int n;
vector<vector<int>> head(maxn);

double dfs(int src, int par) {
    if (head[src].size() <= 1 && src != 1) return 0;
    double sum = 0;  // 孩子节点的期望之和
    int child = 0;  // 孩子节点个数
    for (int nxt : head[src]) {
        if (nxt == par) continue;
        (sum += dfs(nxt, src));
        child += 1;
    }
    return sum / child + 1;
}

int main() {  //: T5-6
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int src, dst; cin >> src >> dst;
        head[src].push_back(dst);
        head[dst].push_back(src);
    }
    printf("%.7lf", dfs(1, 0));
    return 0;
}