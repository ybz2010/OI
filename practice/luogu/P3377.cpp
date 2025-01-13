#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,q;
struct Nahida{int val,ls,rs,fa,dis;}s[maxn];
int find(int rt){return s[rt].fa == rt ? rt : s[rt].fa = find(s[rt].fa);}
int merge(int rt,int x)
{
    if (!rt || !x)
        return rt | x;
    if (s[rt].val > s[x].val || (s[rt].val == s[x].val && rt > x))
        swap(rt,x);
    s[rt].rs = merge(s[rt].rs,x);
    if (s[s[rt].ls].dis < s[s[rt].rs].dis)
        swap(s[rt].ls,s[rt].rs);
    s[s[rt].ls].fa = s[s[rt].rs].fa = s[rt].fa = rt;
    s[rt].dis = s[s[rt].rs].dis + 1;
    return rt;
}
signed main()
{
    s[0].dis = -1;
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&s[i].val);
        s[i].fa = i;
    }
    int op,x,y;
    while (q--)
    {
        scanf("%d%d",&op,&x);
        if (op == 1)
        {
            scanf("%d",&y);
            if (s[x].val == -1 || s[y].val == -1)
                continue;
            x = find(x),y = find(y);
            if (x != y)
                s[x].fa = s[y].fa = merge(x,y);
        }
        else
        {
            if (s[x].val == -1)
            {
                puts("-1");
                continue;
            }
            x = find(x);
            printf("%d\n",s[x].val);
            s[x].val = -1;
            s[s[x].ls].fa = s[x].ls;
            s[s[x].rs].fa = s[x].rs;
            s[x].fa = merge(s[x].ls,s[x].rs);
        }
    }
    return 0;
}