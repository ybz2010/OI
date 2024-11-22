#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 5005;
vector<pair<int, int>> side[maxn];
int n, m, vis[maxn];
long long dis[maxn], ans;
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        side[u].push_back(make_pair(v, w));
        side[v].push_back(make_pair(u, w));
    }
    memset(dis, 0x3f, sizeof(dis));
    int s = 1;
    dis[s] = 0; // dis[i]代表一个未加入联通块的点到联通块的最近距离
    for (int i = 0; i <= n; i++)
        dis[i] = 1e18;
    while (1)
    {
        int now = 0;
        for (int i = 1; i <= n; i++)
            if (!vis[i] && dis[i] < dis[now])
                now = i; // 取一个dis最小的（显然这个点满足通过一条边就能到达联通块，且这条边最小）
        if (!now)
            break;       // 所有点都走过 退出
        ans += dis[now]; // 代表走连接联通块和now之间的边，累计答案
        vis[now] = 1;    // 标记这个点 代表这个点并入联通块
        for (int i = 0; i < side[now].size(); i++)
        {
            int v = side[now][i].first, w = side[now][i].second;
            if (!vis[v])
                dis[v] = min(dis[v], 1ll * w); // 更新不在联通块内的点的dis
        }
    }
    cout << ans;
}
int now = 0;
for (int i = 1; i <= n; i++)
    if (!vis[i] && dis[i] < dis[now])
        now = i; // 取一个dis最小的
vis[now] = 1;
if (now == 0)
    break;
for (int i = 1; i <= n; i++)
    if (!vis[i])
    {
        dis[i] = min(dis[i], get_dis(now, i));
    }
