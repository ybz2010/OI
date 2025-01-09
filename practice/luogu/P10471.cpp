#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int head[maxn],idx = 1;
int dis[maxn],tr[maxn << 4][2],id = 1;
void insert(int x)
{
    int p = 1;
    for (int i = 31; i >= 0; i--)
    {
        int ch = ((x >> i) & 1);
        if (!tr[p][ch])
            tr[p][ch] = ++id;
        p = tr[p][ch];
    }
}
int find(int x)
{
    int p = 1,ret = 0;
    for (int i = 31; i >= 0; i--)
    {
        int ch = ((x >> i) & 1);
        if (tr[p][ch ^ 1])
        {
            ret += (1 << i);
            p = tr[p][ch ^ 1];
        }
        else
            p = tr[p][ch];
    }
    return ret;
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        cin >> dis[i];
        insert(dis[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)    
        ans = max(ans,find(dis[i]));
    cout << ans;
    return 0;
}