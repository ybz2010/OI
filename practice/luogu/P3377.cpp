#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,q;
struct Nahida{int val,ls,rs,fa,dis;}s[maxn];
int find(int x){return s[x].fa == x ? x : s[x].fa = find(s[x].fa);}
int merge(int x,int y)
{
    if (!x || !y)
        return x | y;
    if (s[x].val > s[y].val || (s[x].val == s[y].val && x > y))
        swap(x,y);
    s[x].rs = merge(s[x].rs,y);
    if (s[s[x].ls].dis < s[s[x].rs].dis)
        swap(s[x].ls,s[x].rs);
    s[s[x].ls].fa = s[s[x].rs].fa = s[x].fa = x;
    s[x].dis = s[s[x].rs].dis + 1;
    return x;
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