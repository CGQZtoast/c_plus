#include <iostream>
#include <vector>
#include <queue>
#define inf (1LL << 60)
using namespace std;
typedef long long LL;

const int ways[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m, w;
vector<vector<int>> gmap;
vector<vector<LL>> dst;
LL direct = inf;

void init() {
    scanf("%d %d %d", &n, &m, &w);
    gmap = vector<vector<int>> (n + 2, vector<int>(m + 2, -1));
    dst = vector<vector<LL>>(n + 2, vector<LL>(m + 2, inf));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &gmap[i][j]);
        }
    }
}

LL bfs(int x0, int y0) {
    struct pos {
        int x, y;;
    };
    LL min_cost = inf;
    queue<pos> task;
    task.push({x0, y0}); dst[x0][y0] = 0;
    while (!task.empty()) {
        auto now = task.front(); task.pop();
        int x = now.x, y = now.y;
        if (gmap[x][y] && gmap[x][y] + dst[x][y] < min_cost) {
            min_cost = gmap[x][y] + dst[x][y];
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + ways[i][0], ny = y + ways[i][1];
            if (~gmap[nx][ny] &&  dst[x][y] + w < dst[nx][ny]) {
                dst[nx][ny] = dst[x][y] + w;
                task.push({nx, ny});
            }
        }
    }
    return min_cost;
}

int main() {  //: T5-9
    init();
    LL path = 0;
    path += bfs(1, 1);
    direct = dst[n][m];
    path += bfs(n, m);
    LL ans = min(path, direct);
    if (ans >= inf) {
        printf("-1");
    } else {
        printf("%lld", ans);
    }
    return 0;
}