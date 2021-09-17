#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100002;

int n, m;
vector<int> cat(maxn);
vector<vector<int>> head(maxn);

int dfs(int now, int cnt, int par) {  // cnt: 之前 连续的有猫的节点数
    if (cnt + cat[now] > m) return 0;  // 如果连续有猫的数量大于 m 就不走了
    if (head[now].size() <= 1) return 1;
    int sum = 0;
    for (int nxt : head[now]) {
        if (nxt != par) {
            sum += dfs(nxt, cat[now] ? cnt + 1 : 0, now);
        }
    }
    return sum;
}

int main() {  //: T5-5
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cat[i];
    }
    for (int i = 0; i < n-1; i++) {
        int src, dst;
        cin >> src >> dst;
        head[src].push_back(dst);
        head[dst].push_back(src);
    }
    cout << dfs(1, 0, 0) << endl;
    return 0;
}