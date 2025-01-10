#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n,cnt,rt;
int h[maxn],w[maxn],dp[maxn];
int k(int j){return -2 * h[j];}
int x(int i){return h[i];}
int b(int j){return dp[j] - w[j] + sq(h[j]);}
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
        return;
    }
    else if (lque <= lpos && rque <= rpos)//新线段完全在原线段下
        tree[rt].ln = ln;
    else if (lque < lpos || rque < rpos)
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
int que(int pos,int l,int r,int rt)
{
    if (!rt)
        return inf;
    int ret = tree[rt].ln.f(pos);
    if (l == r)
        return ret;
    int mid = (l + r) >> 1;
    int tmp;
    if (pos <= mid)
        tmp = que(pos,l,mid,tree[rt].ls);
    else
        tmp = que(pos,mid + 1,r,tree[rt].rs);
    ret = min(ret,tmp);
    return ret;
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",h + i);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",w + i);
        w[i] += w[i - 1];
    }
    upd(line(k(1),b(1)),0,2e6,rt);
    for (int i = 2; i <= n; i++)
    {
        dp[i] = que(x(i),0,2e6,rt) + w[i - 1] + sq(h[i]);
        upd(line(k(i),b(i)),0,2e6,rt);
    }
    printf("%lld",dp[n]);
    return 0;
}