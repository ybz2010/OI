#include<bits/extc++.h>
#define inf 0x7f7f7f7f7f7f
#define int long long
using namespace std;
using namespace __gnu_pbds;
const int maxn = 1e5 + 5;
int n,m;
int l[maxn],r[maxn],w[maxn];
int a[maxn],dis[maxn];
bool vis[maxn];
vector<int>x;
gp_hash_table<int,int>id;
struct edge
{
    int v,w;
    edge *nxt;
}*head[maxn << 1];
void adde(int u,int v,int w)
{
    auto tmp = new edge;
    tmp->v = v;
    tmp->w = w;
    tmp->nxt = head[u];
    head[u] = tmp;
}
void spfa(int st)
{
    memset(dis,~0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    queue<int>q;
    dis[st] = 0;
    q.push(st);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto i = head[u]; i; i = i->nxt)
        {
            int v = i->v,w = i->w;
            if (dis[v] < dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }   
}
void mian()
{
    cin >> n >> m;
    x.clear();
    memset(head,0,sizeof head);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    x.push_back(-inf);
    x.push_back(inf);
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i] >> w[i];
        l[i] --;
        x.push_back(l[i]);
        x.push_back(r[i]);
    }
    sort(x.begin(),x.end());
    unique(x.begin(),x.end());
    for (int i = 1; i < x.size(); i++)
        id[x[i]] = i;
    for (int i = 1; i <= m; i++)
        adde(id[l[i]],id[r[i]],w[i]);
    for (int i = 1; i < x.size(); i++)
    {
        int tl = upper_bound(a + 1,a + n + 1,x[i - 1]) - a;
        int tr = upper_bound(a + 1,a + n + 1,x[i]) - a - 1;
        adde(i,i - 1,tl - tr - 1);
        adde(i - 1,i,0);
    }
    spfa(0);
    cout << n - dis[x.size() - 1] << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        mian();
    return 0;
}
//dis[r] - dis[l - 1] >= w;
//dis[r] >= dis[l - 1] + w;
//dis[i] >= dis[i - 1]
//dis[r] <= dis[l - 1] + w;
//dis[l - 1] >= dis[r] - w;