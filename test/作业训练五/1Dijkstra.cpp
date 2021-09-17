#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int max_n = 100002;

struct Edge
{
    int to, val;
};

int n, m;
vector<vector<Edge>> head(max_n);
vector<int> from(max_n); // 记录每个点的「来源」

void dijkstra()
{
    struct Node
    {
        int dst;
        pair<int, string> val;
        bool operator<(const Node &other) const
        {
            return val < other.val;
        }
    };
    priority_queue<Node> task;
    vector<pair<int, string>> dis(max_n, {0x7fffffff, ""});
    task.push({1, {0, "1"}});
    dis[1] = {0, "1"};
    while (!task.empty())
    {
        Node top = task.top();
        task.pop(); // 取出距离最短的点
        if (top.val > dis[top.dst])
            continue;
        for (Edge edg : head[top.dst])
        {
            pair<int, string> nxt = {top.val.first + edg.val, top.val.second + (char)(edg.to + '0')};
            if (nxt < dis[edg.to])
            {
                from[edg.to] = top.dst; // 更新来源
                dis[edg.to] = nxt;
                task.push({edg.to, nxt});
            }
        }
    }
}

int output(int index)
{
    if (from[index] == 0)
    {
        printf("%d ", index);
        return 0;
    }
    output(from[index]);
    printf("%d ", index);
    return 0;
}

int main()
{ //: T5-1
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int src, dst, val;
        cin >> src >> dst >> val;
        head[src].push_back({dst, val}); // 无向图需要建双向边
        head[dst].push_back({src, val});
    }
    dijkstra();

    // 如果走不到则节点 n 的「来源」为 0
    from[n] ? output(n) : printf("-1");
    return 0;
}