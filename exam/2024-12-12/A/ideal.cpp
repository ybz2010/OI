#include<bits/extc++.h>
#define inf 0x7f7f7f7f
#define vector basic_string
#define pvi pair<vector<int>,int>
using namespace std;
int n,m,Q;
vector<int>g[1005];
vector<int>dis[1005];
bool vis[1005];
void dij(int st)
{
    memset(vis,0,sizeof vis);
    for (int i = 1; i <= n; i++)
    {
        dis[i].clear();
        dis[i].push_back(inf);
    }
    priority_queue<pvi,vector<pvi>,greater<pvi> >q;
    dis[st] = {st};
    q.push({{st},st});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto v : g[u])
        {
            if (dis[v] > dis[u] + v)
            {
                dis[v] = dis[u] + v;
                q.push({dis[v],v});
            }
        }
    }
}
signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n >> m >> Q;
    int x,y,k;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        sort(g[i].begin(),g[i].end());
    while (Q--)
    {
        cin >> x >> y >> k;
        dij(x);
        if (dis[y][0] != inf || dis[y].size() < k)
            cout << "-1\n";
        else
            cout << dis[y][k - 1];
    }
    return 0;
}
/*
7 7 5
1 2
2 3
1 3
3 4
4 5
5 3
4 6
1 4 2
2 6 1
1 7 3
1 3 2
1 3 5
*/