// dijkstra只能处理正权边，邻接矩阵适合稠密图
#include <iostream>
#include <cstring>
using namespace std; 

const int N = 510;

// 分别表示构建好的图以及起点到n号点的距离
int g[N][N], dist[N];

// 表示当前点的最短路是否已经确定
bool st[N];
int n, m;

int Dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // 这里不能更新st，因为不能通过1号点去更新别的点
    // st[1] = true;
    for (int i = 0; i < n; ++ i)
    {
        // 找到不在s中的距离最近的点：
        int t = -1;
        for (int j = 1; j <= n; ++ j)
        {
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        
        // 表示已经确定起点到t的距离
        st[t] = true;
        
        // 从t出去的所有的点更新起点到其他点的距离，即t作为中间点
        for (int j = 1; j <= n; ++ j)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    
    // 不需要考虑边以及自环
    while (m --)
    {
        int s, e, d; cin >> s >> e >> d;
        g[s][e] = min(g[s][e], d);
    }
    cout << Dijkstra();
    return 0;
}
