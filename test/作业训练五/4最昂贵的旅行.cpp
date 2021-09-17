#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int to, val;
};

int n;
vector<vector<Edge>> head;
vector<bool> vst;

int dfs(int src, int cost=0) {
    vst[src] = true;
    int max_len = cost;
    for (Edge nxt : head[src]) {
        if (!vst[nxt.to]) {
            max_len = max(max_len, dfs(nxt.to, cost + nxt.val));
        }
    }
    return max_len;
}

int main() {  //: T5-4
    cin >> n;
    head = vector<vector<Edge>>(n);
    for (int i = 0; i < n-1; i++) {
        int src, dst, val;
        cin >> src >> dst >> val;
        head[src].push_back({dst, val});
        head[dst].push_back({src, val});
    }
    vst = vector<bool>(n);
    cout << dfs(0) << endl;
    return 0;
}