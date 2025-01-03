#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) >> 1)
#define push_up(rt) tree[rt].val = min(tree[ls].val,tree[rs].val)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 5e5 + 5;
int n,len;
int v[maxn << 1];
struct Nahida
{
    int val;
    int l,r;
}tree[maxn << 3];
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if (l == r)
    {
        if (l + len - 1 <= n)
            tree[rt].val = v[l + len - 1] - v[l - 1];
        return;
    }
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
int que(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].val;
    int ret = inf;
    if (ql <= mid)
        ret = min(ret,que(ql,qr,ls));
    if (qr > mid)
        ret = min(ret,que(ql,qr,rs));
    return ret;
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",v + i);
        v[i + n] = v[i];
    }
    len = (n + 1) >> 1;
    n <<= 1;
    for (int i = 1; i <= n; i++)
        v[i] += v[i - 1];
    build(1,n,1);
    int ans = 0;
    for (int i = 1; i + len - 1 <= n; i++)
        ans = max(ans,que(i,i + len - 1));
    printf("%lld",ans);
    return 0;
}
//偶遇神秘小博弈，拼尽全力无法战胜