#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int k,a[maxn];
int tr[maxn << 2][2],ed[maxn << 2],vi[maxn << 2],id = 1;
void insert()
{
    int p = 1;
    for (int i = 1; i <= k; i++)
    {
        int ch = a[i];
        if (tr[p][ch] == -1)
            tr[p][ch] = ++id;
        p = tr[p][ch];
        vi[p] ++;
    }
    ed[p] ++;
}
int find()
{
    int p = 1,ret = 0;
    for (int i = 1; i <= k; i++)
    {
        int ch = a[i];
        if (tr[p][ch] == -1)
            return ret;
        p = tr[p][ch];
        ret += ed[p];
    }
    return ret - ed[p] + vi[p];
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    memset(tr,-1,sizeof tr);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",&k);
        for (int j = 1; j <= k; j++)
            scanf("%lld",a + j);
        insert();
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld",&k);
        for (int j = 1; j <= k; j++)
            scanf("%lld",a + j);
        printf("%lld\n",find());
    }
    return 0;
}