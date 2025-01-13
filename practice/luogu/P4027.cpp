#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long double ld;
const int maxn = 1e5 + 5;
const ld eps = 1e-12;
int n,tree[maxn << 2];
ld a[maxn],b[maxn],r[maxn];
ld k[maxn],y[maxn],ans;
ld x1[maxn],x2[maxn];
ld f(int x,int id){return x1[x] * k[id] + y[id];}
void upd(int ln,int l,int r,int rt)
{
    if (l == r)
    {
        if (f(l,ln) > f(l,tree[rt]))
            tree[rt] = ln;
        return;
    }
    int mid = (l + r) >> 1;
    if (f(mid,ln) > f(mid,tree[rt]))
        swap(ln,tree[rt]);
    if (f(l,ln) > f(l,tree[rt]))
        upd(ln,l,mid,ls);
    else
        upd(ln,mid + 1,r,rs);
}
ld que(int pos,int l,int r,int rt)
{
    int mid = (l + r) >> 1;
    ld ret = f(pos,tree[rt]);
    if (l == r)
        return ret;
    if (pos <= mid)
        ret = max(ret,que(pos,l,mid,ls));
    else
        ret = max(ret,que(pos,mid + 1,r,rs));
    return ret;
}
signed main()
{
    scanf("%d%Lf",&n,&ans);
    for (int i = 1; i <= n; i++)
    {
        scanf("%Lf%Lf%Lf",a + i,b + i,r + i);
        x1[i] = x2[i] = a[i] / b[i];
    }
    sort(x1 + 1,x1 + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(x1 + 1,x1 + n + 1,x2[i]) - x1;
        ans = max(ans,b[i] * que(pos,1,n,1));
        k[i] = ans * r[i] / (a[i] * r[i] + b[i]);
        y[i] = ans / (a[i] * r[i] + b[i]);
        upd(i,1,n,1);
    }
    printf("%.3Lf",ans);
    return 0;
}