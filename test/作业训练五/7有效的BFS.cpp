#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

const int maxn = 100002;

inline int read() {
    int x; cin >> x;
    return x;
}

int n;
vector<set<int>> head(maxn);
vector<int> parent(maxn);  // 标记父节点

void dfs(int now, int par) {
    parent[now] = par;
    for (int nxt : head[now]) {
        if (nxt == par) continue;
        dfs(nxt, now);
    }
}

bool bfs() {  // 直接模拟 bfs
    queue<int> task;
    task.push(read());
    while (!task.empty()) {
        int now = task.front(); task.pop();
        for (int nxt : head[now]) {
            if (nxt == parent[now]) continue;
            int except = read();
            if (head[now].find(except) == head[now].end()) {
                return false;
            }
            task.push(except);
        }
    }
    return true;
}

int main() {  //: T5-7
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int src, dst;
        cin >> src >> dst;
        head[src].insert(dst);
        head[dst].insert(src);
    }
    dfs(1, 0);
    printf(bfs() ? "Yes" : "No");
    return 0;
}