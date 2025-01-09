#include<bits/extc++.h>
#define int long long
#define inf 0x7f7f7f7f7f7f7f7f
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;
void operator+=(pii &x,pii &y)
{
    if(x.first != y.first)
    {
        if(x.first > y.first)
            x = y;
    }
    else
        x.second = (x.second + y.second) % mod;
}
int n,m;
int a[maxn],b[maxn];
int pre[maxn];
struct Rukhadevata
{
    int l,r;
    pii val;
}tree[maxn << 2];
void push_down(int rt)
{
    if (tree[rt].val.first == inf)
        return;
    tree[rt << 1].val += tree[rt].val;
    tree[rt << 1 | 1].val += tree[rt].val;
    tree[rt].val = mkp(inf,0);
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].val = mkp(inf,0);
    if (l == r)
    {
        if (l == 1)
            tree[rt].val = mkp(0,1);
        return;
    }
    int mid = l + r >> 1;
    build(l,mid,rt << 1);
    build(mid + 1,r,rt << 1 | 1);
}
void upd(int ql,int qr,pii x,int rt)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
    {
        tree[rt].val += x;
        return;
    }
    push_down(rt);
    int mid = l + r >> 1;
    if (ql <= mid)
        upd(ql,qr,x,rt << 1);
    if (qr > mid)
        upd(ql,qr,x,rt << 1 | 1);
}
pii que(int x,int rt)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (l == r)
        return tree[rt].val;
    push_down(rt);
    int mid = l + r >> 1;
    if (x <= mid)
        return que(x,rt << 1);
    else
        return que(x,rt << 1 | 1);
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        pre[i] = pre[i - 1] + a[i];
    }
    for (int j = 1; j <= m; j++)
        scanf("%lld",b + j);
    build(1,n,1);
    pii ans = mkp(inf,0);
    for (int j = 1; j <= m; j++)
    {
        pii tmp1 = mkp(inf,0);
        for (int i = 1; i <= n; i++)
        {
            int pos = upper_bound(pre + i,pre + n + 1,b[j] + pre[i - 1]) - pre;
            if (i < pos)
            {
                pii tmp2 = que(i,1);
                tmp2.first += m - j;
                if (pos == n + 1)
                {
                    tmp1 += tmp2;
                    pos --;
                }
                if (i < pos)
                    upd(i + 1,pos,tmp2,1);
            }
        }
        ans += tmp1;
    }
    if (ans.first != inf)
        printf("%lld %lld\n",ans.first,ans.second);
    else
        puts("-1");
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}