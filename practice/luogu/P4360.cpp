#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e4 + 5;
int n,tot,rt,cnt;
int w[maxn],sum[maxn],dis[maxn];
int k(int j){return sum[j];}
int x(int i){return dis[i];}
int b(int j){return -dis[j] * sum[j];}
struct line
{
    int k,b;
    line(int k = 0,int b = 0):k(k),b(b){};
    int f(int x){return k * x + b;}
};
struct Nahida
{
    int ls,rs;
    line ln;
    bool fl;
}tree[maxn << 2];
void upd(line ln,int l,int r,int &rt)
{
    if (!rt)
        rt = ++cnt;
    int lpos = tree[rt].ln.f(l),rpos = tree[rt].ln.f(r);
    int lque = ln.f(l),rque = ln.f(r);
    if (!tree[rt].fl)
    {
        tree[rt].ln = ln;
        tree[rt].fl = 1;
    }
    else if (lque < lpos && rque < rpos)
        tree[rt].ln = ln;
    else
    {
        int mid = (l + r) >> 1;
        if (ln.f(mid) < tree[rt].ln.f(mid))
            swap(ln,tree[rt].ln);
        if (ln.f(l) < tree[rt].ln.f(l))
            upd(ln,l,mid,tree[rt].ls);
        else
            upd(ln,mid + 1,r,tree[rt].rs);
    }
}
int que(int pos,int l,int r,int &rt)
{
    if (!rt)
        return inf;
    int ret = tree[rt].ln.f(pos);
    if (l == r)
        return ret;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        ret = min(ret,que(pos,l,mid,tree[rt].ls));
    else
        ret = min(ret,que(pos,mid + 1,r,tree[rt].rs));
    return ret;
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld",w + i,dis + i);
        sum[i] = sum[i - 1] + w[i];
    }
    for (int i = n; i >= 1; i--)
    {
        dis[i] += dis[i + 1];
        tot += dis[i] * w[i];
    }
    int ans = inf;
    upd(line(k(1),b(1)),1,1e5,rt);
    for (int i = 2; i <= n; i++)
    {
        ans = min(ans,que(x(i),1,1e5,rt) + tot - dis[i] * sum[i]);
        upd(line(k(i),b(i)),1,1e5,rt);
    }
    printf("%lld",ans);
    return 0;
}