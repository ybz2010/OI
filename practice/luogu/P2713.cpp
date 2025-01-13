#include<bits/extc++.h>
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 1e6 + 5;
int n,m;
struct Nahida{int lson,rson,val,fa,dis;bool dead;}tree[maxn];
int find(int rt){return rt == tree[rt].fa ? rt : tree[rt].fa = find(tree[rt].fa);}
int merge(int rt,int x)
{
    if (!rt || !x)
        return rt | x;
    if (tree[rt].val > tree[x].val)
        swap(rt,x);
    tree[rt].rson = merge(rs,x);
    if (tree[ls].dis < tree[rs].dis)
        swap(ls,rs);
    tree[ls].fa = tree[rs].fa = tree[rt].fa = rt;
    tree[rt].dis = tree[rs].dis + 1;
    return rt;
}
void pop(int rt)
{
    tree[rt].dead = 1;
    tree[rt].fa = tree[ls].fa = tree[rs].fa = merge(ls,rs);
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&tree[i].val);
        tree[i].fa = i;
    }
    scanf("%d",&m);
    char op;
    int x,y;
    while (m--)
    {
        cin >> op >> x;
        if (op == 'M')
        {
            cin >> y;
            if (tree[x].dead || tree[y].dead)
                continue;
            x = find(x),y = find(y);
            if (x != y)
                merge(x,y);
        }
        else
        {
            if (tree[x].dead)
                puts("0");
            else
            {
                x = find(x);
                printf("%d\n",tree[x].val);
                pop(x);
            }
        }
    }
    return 0;
}