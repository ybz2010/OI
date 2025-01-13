#include<bits/extc++.h>
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
struct Nahida
{
    int dis,val,fa,lson,rson;
    Nahida(){dis = val = fa = lson = rson = 0;};
}tree[maxn];
int find(int rt){return rt == tree[rt].fa ? rt : tree[rt].fa = find(tree[rt].fa);}
int merge(int rt,int x)
{
    if (!rt || !x)
        return rt | x;
    if (tree[rt].val < tree[x].val)
        swap(rt,x);
    rs = merge(rs,x);
    if (tree[ls].dis < tree[rs].dis)
        swap(ls,rs);
    tree[rt].dis = tree[rs].dis + 1;
    return rt;
}
int process(int rt)
{
    tree[rt].val >>= 1;
    int tmp = merge(ls,rs);
    ls = rs = tree[rt].dis = 0;
    return tree[tmp].fa = tree[rt].fa = merge(tmp,rt);
}
void solve()
{
    fill(tree + 1,tree + n + 1,Nahida());
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&tree[i].val);
        tree[i].fa = i;
    }
    scanf("%d",&m);
    int x,y;
    while (m--)
    {
        scanf("%d%d",&x,&y);
        int fx = find(x),fy = find(y);
        if (fx == fy)
        {
            puts("-1");
            continue;
        }
        fx = process(fx);
        fy = process(fy);
        tree[fx].fa = tree[fy].fa = merge(fx,fy);
        printf("%d\n",tree[find(fx)].val);
    }
}
signed main()
{
    while (scanf("%d",&n) != EOF)
        solve();
    return 0;
}